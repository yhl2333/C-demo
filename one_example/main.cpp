#include <iostream>
#include <mutex>
//懒汉模式
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

//饿汉模式
class Singleton1 {
private:
    static Singleton1* instance;
    Singleton1() {}
public:
    static Singleton1* getInstance() {
        return instance;
    }
};
    
Singleton1* Singleton1::instance = new Singleton1();


//双重检测


class Singleton2 {
private:
    static std::mutex mtx;
    static volatile Singleton2* instance;
    
    // 私有构造函数和拷贝构造函数
    
public:
    static volatile Singleton2* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {  // double-checked locking
                instance = new Singleton2();
            }
        }
        return instance;
    }
};

volatile Singleton2* Singleton2::instance = nullptr;
std::mutex Singleton2::mtx;


int main(int, char**){
    std::cout << "Hello, from one_example!\n";
}
