#include <iostream>
#include <memory>
#include <vector>
using namespace std;


void unique_double_control(){
    string* str = new string("I'm Li Ming!");
    unique_ptr<string> p3(str);
    unique_ptr<string> p4(str);
    (*p4)[0] = 'A';
    (*p3)[1] = 'B';
    std::cout<<*p3<<endl;

}

void shared_double_control(){
    string* str_share = new string("I'm Li Ming!");
    shared_ptr<string> p5(str_share);
    shared_ptr<string> p6(str_share);
    std::cout<<"use_count"<<p5.use_count()<<p6.use_count()<<std::endl;
}

int main(int, char**){



    std::cout<<"unique_ptr---------------------------------------------------"<<std::endl;

    unique_ptr<string> p1(new string("I'm Li Ming!"));
    unique_ptr<string> p2(new string("I'm age 22."));
	
    cout << "p1:" << p1.get() << endl;
    cout << "p2:" << p2.get() << endl;

    p1 = std::move(p2);

    cout << "p1:" << p1.get() << endl;
    cout << "p2:" << p2.get() << endl;


    vector<unique_ptr<string>> v;
    v.push_back(std::move(p1));
    v.push_back(std::move(p2));
    cout << "v[0]:" << v[0].get() << endl;
    cout << "v[1]:" << v[1].get() << endl;

    v[1] = std::move(v[0]);

    cout << "v[0]:" << v[0].get() << endl;
    cout << "v[1]:" << v[1].get() << endl;

    //unique_double_control();//这里一个指针被两个unique_ptr管理，出现了两次delete，导致程序崩溃


    std::cout<<"shared_ptr---------------------------------------------------"<<std::endl;
    //shared_double_control();//这里两个shared_ptr计数都为1，但是指向同一块内存，所以被释放了两次，导致程序崩溃。

    std::cout << "Hello, from smart_ptr!\n";
}
