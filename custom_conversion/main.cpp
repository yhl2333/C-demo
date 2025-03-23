using namespace std;
#include <iostream>

class MyType {
    private:
        int value;
        int num;
    public:
        // 构造函数
        MyType(int v, int num) : value(v) , num(num){}
        
        // 自定义类型转换运算符（隐式或显式）
        operator int() const { 
            std::cout << "operator int() called" << std::endl;
            return num; // 将MyType对象转换为int型
        }
};








    
int main() {
    MyType obj(42,11);
        
    int num = obj; // 隐式调用operator int()
    std::cout << num << std::endl;
    // 或者
    int num2 = static_cast<int>(obj); // 显式调用
        
    return 0;
}