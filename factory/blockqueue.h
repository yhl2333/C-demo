#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

//先入先出队列
//采用环形数组，没有使用队列
#include "locker.h"
#define QUEUE_MAX 4

template <class T>
class Blockqueue {
public:

    Blockqueue(int queue_max_size) : m_max_size(queue_max_size){

        m_array = new T[m_max_size];
        m_front = -1;
        m_back = -1;
        m_size = 0;

    }

    ~Blockqueue(){
        delete[] m_array;
        m_array = nullptr;
    }

    bool push(const T& item){

        m_locker.lock();       
        if(m_size>=m_max_size)
        {
            std::cout<<"阻塞队列已满,无法push";
            m_cond.broadcast();
            m_locker.unlock();
            return -1;
        }
        else{

            m_front = (m_front+1)%m_max_size;
            m_array[m_front%m_max_size] = item;
            m_size++;
            m_cond.broadcast();
            m_locker.unlock();
            std::cout<<m_front<<std::endl;
            return 1;
        }


    }

    bool pop(T& item){
        m_locker.lock();

        while(m_size <= 0)
        {   
            if(!m_cond.wait(m_locker.get()))
            {
                m_locker.unlock();
                return false;
            }
        }
            
        m_back = (m_back+1)%m_max_size;
        item = m_array[m_back];
        m_size--;
        m_locker.unlock();
        return 1;


  
    }

    bool pop(){
        m_locker.lock();

        while(m_size <= 0)
        {   
            if(!m_cond.wait(m_locker.get()))
            {
                m_locker.unlock();
                return false;
            }
        }

        m_back = (m_back+1)%m_max_size;
        m_size--;
        m_locker.unlock();
        return 1;

            

        
  
    }


    bool front(T& item){
        m_locker.lock();
        if(m_size!=0)
        {
            item = m_array[m_front];
            m_locker.unlock();
            return 1;
        }
        else
        {           
            m_locker.unlock();
            return -1;
        }
            
        
    }

    bool back(T& item){
        m_locker.lock();
        if(m_size!=0)
        {
            item = m_array [m_back];
            m_locker.unlock();
            return 1;
        }
        else
        {
            m_locker.unlock();
            return -1;
        }
            

        
    }


    // 实现的没有问题,返回的是进入函数时，容器内部是满还是不满
    bool full()
    {
        m_locker.lock();
        if(m_size>= m_max_size)
        {
            m_locker.unlock();
            return true;
        }
        m_locker.unlock();
        return false;
    }

    // 实现的没有问题
    bool empty()
    {
        m_locker.lock();
        if (0 == m_size)
        {
            m_locker.unlock();
            return true;
        }
        m_locker.unlock();
        return false;
    }



    //不安全的方法
    int size(){
        return m_size;
    }


private:
    T* m_array;
    int m_max_size;
    int m_front;
    int m_back;
    int m_size;

    locker m_locker;
    cond m_cond;

};

#endif