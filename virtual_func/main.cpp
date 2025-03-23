#include <iostream>
#include <typeinfo>

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
    void func() override { std::cout << "Derived::func()" <<derived_data2<< std::endl; }
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
    //std::cout << "Derived data: " << &derived_ptr->derived_data << std::endl;//这里通过Base指针访问Derived的成员变量是不行的,访问成员函数也是不行的，sizeof(*derived_ptr)也是Base的大小，因此需要dynamic_cast和static_cast来进行转换。同理析构函数也需要virtual来实现多态
    //derived_ptr->func();//但是在虚函数中，可以访问到该成员变量


    //RTTI
    //dynamic_cast和static_cast的区别
    Derived* derived_ptr2 = dynamic_cast<Derived*>(derived_ptr);
    if (derived_ptr2) {
        std::cout << "dynamic_cast Derived data: " << derived_ptr2->derived_data << std::endl;
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    Derived* derived_ptr3 = dynamic_cast<Derived*>(base_ptr);
    if (derived_ptr3) {
        std::cout << "dynamic_cast Derived data: " << derived_ptr3->derived_data << std::endl;
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    //typeinfo

    if(typeid(*base_ptr)==typeid(Base)){
        std::cout<<"base_ptr is Base"<<std::endl;
    }
    if(typeid(*derived_ptr)==typeid(Derived)){
        std::cout<<"derived_ptr is Derived"<<std::endl;
    }
    std::cout << "typeid of base_ptr: " << typeid(*base_ptr).name() << std::endl;
    std::cout << "typeid of derived_ptr: " << typeid(*derived_ptr).name() << std::endl;

    Derived* derived_ptr4 = static_cast<Derived*>(derived_ptr);
    if (derived_ptr4) {
        std::cout << "static_cast Derived data: " << derived_ptr4->derived_data << std::endl;
    } else {
        std::cout << "static_cast failed" << std::endl;
    }

    Derived* derived_ptr5 = static_cast<Derived*>(base_ptr);
    if (derived_ptr5) {
        std::cout << "static_cast Derived data: " << derived_ptr5->derived_data << std::endl; //这里输出是0，是不对的，但是static_cast不会检查类型，所以不会报错，dynamic_cast会检查类型，并把指针置空
    } else {
        std::cout << "static_cast failed" << std::endl;
    }

    delete base_ptr;
    delete derived_ptr;

    
    return 0;
}