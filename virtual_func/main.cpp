#include <iostream>

class Base {
public:
    virtual void func() { std::cout << "Base::func()" << std::endl; }
    virtual ~Base(){
        std::cout<<"Base::~Base()"<<std::endl;
    };

    int base_data=1;
    int base_data2=2;
};

class Derived : public Base {
public:
    void func() override { std::cout << "Derived::func()" << std::endl; }
    ~Derived(){
        std::cout<<"Derived::~Derived()"<<std::endl;
    };
    int derived_data=3;
    int derived_data2=4;
};

int main() {
    //有关虚函数地址的问题
    Base base;

    void** vptr = *(void***) &base;

    std::cout<<"vptr: "<<vptr<<std::endl;

    void** virtual_func1 = *(void***)vptr;
    std::cout<<"virtual_func1: "<<virtual_func1<<std::endl;

    using FnType = void(*)(Base*);
    FnType funcBase = (FnType)vptr[0];//FnType funcBase = (FnType)(*vptr);FnType funcBase = (FnType)virtual_func1;也是可以的

    funcBase(&base);  // 调用 Derived::show()    //((void(*)(Base*))vptr[0])(base);//也可以实现调用

    Derived derived;
    
    std::cout << "Base vtable pointer: " << *(void**)(&base) << std::endl;
    std::cout << "Derived vtable pointer: " << *(void**)(&derived) << std::endl;


    //有关成员变量的地址

    Base* base_ptr = new Base();
    Base* derived_ptr = new Derived();

    std::cout << "Size of Base: " << sizeof(*base_ptr) << " bytes" << std::endl;
    std::cout << "Size of Derived: " << sizeof(*derived_ptr) << " bytes" << std::endl;

    std::cout << "address of Base: " << base_ptr << std::endl;
    std::cout << "address of Derived: " << derived_ptr << std::endl;
    std::cout << "Base data: " << &base_ptr->base_data << std::endl;
    std::cout << "Derived data: " << &derived_ptr->base_data << std::endl;
    // std::cout << "Derived data: " << &derived_ptr->derived_data << std::endl;//这里通过Base指针访问Derived的成员变量是不行的,访问成员函数也是不行的，sizeof(*derived_ptr)也是Base的大小，因此需要dynamic_cast和static_cast来进行转换。同理析构函数也需要virtual来实现多态

    delete base_ptr;
    delete derived_ptr;

    
    return 0;
}