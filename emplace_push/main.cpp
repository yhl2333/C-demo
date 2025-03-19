#include <iostream>
#include <vector>

using namespace std;

class MyTest
{
public:
    //普通构造
    MyTest(int id,int age):m_id(id),m_age(age)
    { 
        cout << "ceate MyTest class..." << this << endl;
    }
    //拷贝构造
    MyTest(const MyTest &t):m_id(t.m_id),m_age(t.m_age)
    {  
        cout << "copy construct called..." << this << endl;
    }
    //移动构造
    MyTest(MyTest &&t)
    {
        m_id = std::move(t.m_id);
        m_age = std::move(t.m_age);
        cout << "move contruct called.." << this << endl;
    }
    //析构
    ~MyTest()
    {
        cout << "destory MyTest class..." << this << endl;
    }
private:
    int m_id; //id成员
    int m_age;//age成员
};




int main(int, char**){


    std::vector<MyTest> vec;

    vec.reserve(20); 
    MyTest t1(1,2);
    MyTest t2(3,4);



    std::cout<<"push_back lvalue"<<"-----------------------------------------"<<std::endl;
    vec.push_back(t1);

    std::cout<<"push_back temp-rvalue"<<"-----------------------------------------"<<std::endl;
    vec.push_back(MyTest(1,2));

    std::cout<<"push_back rvalue"<<"-----------------------------------------"<<std::endl;
    vec.push_back(std::move(t1));

    std::cout<<"emplace_back lvalue"<<"-----------------------------------------"<<std::endl;
    vec.emplace_back(t2);

    std::cout<<"emplace_back temp-rvalue"<<"-----------------------------------------"<<std::endl;
    vec.push_back(MyTest(1,2));

    std::cout<<"emplace_back rvalue"<<"-----------------------------------------"<<std::endl;
    vec.emplace_back(std::move(t2));

    std::cout<<"emplace_back reference"<<"-----------------------------------------"<<std::endl;
    vec.emplace_back(3,4);


    std::cout<<"over"<<"-----------------------------------------"<<std::endl;

}
