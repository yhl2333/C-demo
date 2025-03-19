#include <iostream>

class Base {
public:
    virtual void func() { std::cout << "Base::func()" << std::endl; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void func() override { std::cout << "Derived::func()" << std::endl; }
};

int main() {
    Base base;


    void** vptr = *(void***) &base;

    std::cout<<"vptr: "<<vptr<<std::endl;

    void** virtual_func1 = *(void***)vptr;
    std::cout<<"virtual_func1: "<<virtual_func1<<std::endl;

    using FnType = void(*)(Base*);
    FnType funcBase = (FnType)vptr[0];//FnType funcBase = (FnType)(*vptr);FnType funcBase = (FnType)virtual_func1;也是可以的

    funcBase(&base);  // 调用 Derived::show()

    //((void(*)(Base*))vptr[0])(base);//也可以实现调用


    Derived derived;
    
    std::cout << "Base vtable pointer: " << *(void**)(&base) << std::endl;
    std::cout << "Derived vtable pointer: " << *(void**)(&derived) << std::endl;
    
    return 0;
}