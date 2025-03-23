#include <iostream>

#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor" << std::endl; }
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

class Member: public Derived {
public:
    Member() { std::cout << "Member constructor" << std::endl; }
    ~Member() { std::cout << "Member destructor" << std::endl; }
};

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor" << std::endl; }

private:
    Member member;
};

int main(int, char**){
    MyClass myClass;
}
