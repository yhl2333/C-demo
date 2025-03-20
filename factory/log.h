#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <sys/time.h>
#include "blockqueue.h"
#include "locker.h"




class Log{

public:

    static Log* instanse(){
        static Log* log_Base = new Log();
        return log_Base;
    }

    static void *write_log_thread(void *args)
    {
        Log::instanse()->asyn_log_write();
        return nullptr;
     
    }
 
    bool init(const char* filename, int log_buf_size, int split_lines, int max_queue_size){

        if(max_queue_size >=1)
        {
            m_is_async = true;
            m_log_queue = new Blockqueue<string>(max_queue_size);
            pthread_t tid;
            pthread_create(&tid, NULL, write_log_thread, NULL);
        }


        m_log_buf_size = log_buf_size;
        m_buf = new char[m_log_buf_size];
        memset(m_buf,'\0',m_log_buf_size);
        m_split_lines = split_lines;

        time_t t = time(NULL);
        struct tm* sys_tm = localtime(&t);
        struct tm my_tm = *sys_tm;


        const char* p = strrchr(filename, '/');
        char new_log_file_name[256] = {0};

        //如果没文件，就创建。有文件就抄下名字。
        if(p == NULL)
        {
            snprintf(new_log_file_name, 255, "%d_%02d_%02d_%s%s",my_tm.tm_year+1900, my_tm.tm_mon+1, my_tm.tm_mday, filename, ".0");
        } 
        else
        {
            strcpy(log_name, p + 1);
            strncpy(dir_name, filename, p-filename+1);   
            snprintf(new_log_file_name, 255, "%s%d_%02d_%02d_%s%s", dir_name, my_tm.tm_year+1900, my_tm.tm_mon+1, my_tm.tm_mday, log_name, ".0");

        }

        m_today = my_tm.tm_mday;

        m_fp = fopen(new_log_file_name, "a");

        if(m_fp == NULL)
        {

            return false;
        }

        return true;




    }


    void log_write(int level, const char* format, ...)
    {

        // struct timeval {
        //     time_t      tv_sec;   // 秒数
        //     suseconds_t tv_usec;  // 微秒数
        // };

        struct timeval now = {0,0};
        gettimeofday(&now, NULL);
        // typedef long time_t;
        time_t t = now.tv_sec;

        // struct tm {
        //     int tm_sec;    // 秒，范围从 0 到 60
        //     int tm_min;    // 分，范围从 0 到 59
        //     int tm_hour;   // 小时，范围从 0 到 23
        //     int tm_mday;   // 一个月中的某天，范围从 1 到 31
        //     int tm_mon;    // 月份，范围从 0 到 11 (0 表示一月)
        //     int tm_year;   // 自 1900 年起的年数
        //     int tm_wday;   // 一周中的某天，范围从 0 到 6 (0 表示星期天)
        //     int tm_yday;   // 一年中的某天，范围从 0 到 365
        //     int tm_isdst;  // 夏令时标志
        // };

        struct tm* sys_tm = localtime(&t);
        struct tm my_tm = *sys_tm;

        char s[16] ={0};

        switch(level)
        {
        case 0:
            strcpy(s, "[debug]:");
            break;
        case 1:
            strcpy(s, "[info]:");
            break;
        case 2:
            strcpy(s, "[warn]:");
            break;
        case 3:
            strcpy(s, "[erro]:");
            break;
        default:
            strcpy(s, "[info]:");
            break;
        }


        m_mutex.lock();

        if(m_today != my_tm.tm_mday || m_lines_count % m_split_lines == 0 && m_lines_count!=0)//新的一天或者当天的某个日志记录满了
        {
            

            char new_log[256] = {0};
            fflush(m_fp);
            fclose(m_fp);
            char tail[16] = {0};

            snprintf(tail, 16, "%d-%02d-%02d-",my_tm.tm_year +1900, my_tm.tm_mon+1,my_tm.tm_mday);

            if(m_today != my_tm.tm_mday)
            {
                snprintf(new_log, 255, "%s%s%s", dir_name, tail, log_name);
                m_today = my_tm.tm_mday;
                m_lines_count = 0;
            }
            else{
                snprintf(new_log, 255, "%s%s%s.%lld", dir_name, tail, log_name, m_lines_count/m_split_lines);
            }
            m_fp = fopen(new_log, "a");


        }
        m_lines_count++;
        m_mutex.unlock();

        va_list valist;
        va_start(valist, format);

        string log_str;
        m_mutex.lock();

        int n = snprintf(m_buf, 48, "%d-%02d-%02d %02d:%02d:%02d.%06ld %s ",
                     my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday,
                     my_tm.tm_hour, my_tm.tm_min, my_tm.tm_sec, now.tv_usec, s);

        int m = vsnprintf(m_buf + n, m_log_buf_size - n - 1, format, valist);//这个-1留给/0；
        m_buf[n + m] = '\n';    //这里把原来的/0变为/n
        m_buf[n + m + 1] = '\0';//后面再加一个/0
        log_str = m_buf;

        m_mutex.unlock();

        if(m_is_async && !m_log_queue->full())
        {
            m_log_queue->push(log_str);
        }
        else
        {
            m_mutex.lock();
            fputs(log_str.c_str(),m_fp);
            m_mutex.unlock();
        }

        va_end(valist);


    }


    void flush(void)
    {
        m_mutex.lock();
        fflush(m_fp);
        m_mutex.unlock();
    }



private:
    Log():dir_name{0},log_name{0}{    
        m_lines_count = 0;
        m_is_async = false;
    };
    ~Log(){};

    void asyn_log_write(){

        std::cout << "Current thread ID: " << pthread_self() << std::endl;
        string single_log;
        while (m_log_queue->pop(single_log))
        {
            m_mutex.lock();
            fputs(single_log.c_str(),m_fp);
            m_mutex.unlock();
        }
    }


    int m_split_lines;  //日志最大行数
    bool m_is_async;   //是否异步，多线程记录日志
    locker m_mutex;     //是否加锁

    int m_log_buf_size;   //日志缓冲区
    char* m_buf;            
    long long m_lines_count; //日志的某一行

    FILE *m_fp;
    char dir_name[128];
    char log_name[128];
    int m_today;                                        
    
    Blockqueue<string>* m_log_queue;



};


#define LOG_DEBUG(format, ...)  {Log::instanse()->log_write(0, format, ##__VA_ARGS__); Log::instanse()->flush();}
#define LOG_INFO(format, ...)  {Log::instanse()->log_write(1, format, ##__VA_ARGS__); Log::instanse()->flush();}
#define LOG_WARN(format, ...)  {Log::instanse()->log_write(2, format, ##__VA_ARGS__); Log::instanse()->flush();}
#define LOG_ERROR(format, ...)  {Log::instanse()->log_write(3, format, ##__VA_ARGS__); Log::instanse()->flush();}