#include <stdio.h>
#include <map>
#include <iostream>
#include "string.h"
#include "my_product.h"
#include "blockqueue.h"
#include "log.h"




// void foo(int a)
// {
//     std::cout<<a;
// }

// void (*p)(int a);
// p(8);
// (*p)(8);

int main()
{

// ========================== 生产耐克球鞋过程 ===========================//
   // 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
   ProductRegister<Shoes, NikeShoes> nikeShoes("nike");
   ProductRegister<Shoes, AdiShoes> nikeClothes("Adi");
   ProductRegister<Clothes,NikeClothes> NikonClothes("nike"); 
   // 从工厂获取产品种类为Shoes，名称为nike的产品对象
   Shoes *pNiKeShoes =Factory<Shoes>::instance().get_product("nike");
   Shoes *pAdiShoes =Factory<Shoes>::instance().get_product("Adi");
   Clothes *pNiKeClothe = Factory<Clothes>::instance().get_product("nike");
   // 显示产品的广告语
   pNiKeShoes->product();
   pAdiShoes->product();
   pNiKeClothe->product();



   // 释放资源
   if (pNiKeShoes)
   {
      delete pNiKeShoes;
   }

   if (pNiKeClothe)
   {
      delete pNiKeClothe;
   }


   return 0;


   
   // std::cout << "Current thread ID: " << pthread_self() << std::endl;
   // Log::instanse()->init("./log/ServerLog",  2000, 800000, 0); //第一个：文件路径。第二个
   // int num =100;

   // while(num>0)
   // {
   //    LOG_DEBUG("This is a debug message: %d", 42);
   //    LOG_INFO("%s", "adjust timer once");
   //    LOG_ERROR("occur error %s,,,%d ","dasd",65)
   //    LOG_DEBUG("This is a debug message: %d", 42);
   //    LOG_INFO("%s", "adjust timer once");
   //    LOG_ERROR("occur error %s,,,%d ","dasd",65)
   //    LOG_DEBUG("This is a debug message: %d", 42);
   //    LOG_INFO("%s", "adjust timer once");
   //    LOG_ERROR("occur error %s,,,%d ","dasd",65)
   //    LOG_DEBUG("This is a debug message: %d", 42);
   //    LOG_INFO("%s", "adjust timer once");
   //    LOG_ERROR("occur error %s,,,%d ","dasd",65)
   //    num--;
   // }







}





// #include <thread>
// #include <queue>
// #include <iostream>
// #include <condition_variable>
// //#include<invoke.h>
// #include <mutex>

// template <typename T> //生产者消费者模式
// class Queue
// {
// public:
//     Queue(int maxn = 20) : thread_maxnum(maxn) {}
//     //最大线程数量与CPU核数相关

//     //生产者
//     bool Push(const T &val)
//     {
//         std::unique_lock<std::mutex> locker(m_mtx);
//         if (mq.size() >= thread_maxnum)
//         {
//             m_cond_Full.wait(locker);   //超出缓冲区加锁
//             return false;
//         }
        
//         m_cond_Empty.notify_all();  //解锁互斥量，唤醒消费者线程
//         mq.push(val);
//         return true;
//     }

//     //消费者
//     T Pop()
//     {
//         std::unique_lock<std::mutex> locker(m_mtx);
//         while (mq.empty())
//         {
//             std::cout<<mq.size()<<"阻塞"<<std::endl;
//             m_cond_Empty.wait(locker);  //缓冲队列为空上锁，阻塞消费者线程
//         }

//         T val = mq.front();
//         mq.pop();
//         m_cond_Full.notify_all(); //解锁互斥量，唤醒生产者线程
//         return val;
//     }

// private:
//     std::queue<T> mq;
//     std::mutex m_mtx;               //互斥锁
//     int thread_maxnum;              //最大线程数量，缓冲区数量
//     std::condition_variable m_cond_Empty; //条件变量，对应消费者线程
//     std::condition_variable m_cond_Full; //条件变量，对应生产者线程
// };

// void producer(Queue<int> *q)
// {
//     for (int i = 0; i < 500; i++)
//     {
//         if (q->Push(i))
//             std::cout << "push: " << i << "\n";
//         else
//             std::cout << "push failed!\n";
//         //std::this_thread::sleep_for(std::chrono::seconds(1000));
//     }
// }

// void consumer(Queue<int> *q)
// {
//     for (int i = 0; i < 500; i++)
//     {
//         auto t = q->Pop();
//         std::cout << i<< "pop: " << t << "\n";

//         //std::this_thread::sleep_for(std::chrono::seconds(500));
//     }
// }
// int main()
// {
//     Queue<int> q(200);
//     std::thread t1(producer, &q);
//     std::thread t2(consumer, &q);

//     t1.join();
//     t2.join();
//     return 0;
// }
