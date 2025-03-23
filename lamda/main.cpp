#include <iostream>

class __lambda_1
{
public:
    __lambda_1(int x) : __x(x) {} // 构造函数，用于初始化捕获的变量
    int operator() (int y) const // 重载的 operator()，用于调用 Lambda表达式
    {
        return __x + y; // 函数体，与 Lambda表达式的函数体相同
    }
private:
    int __x; // 数据成员，用于存储捕获的变量
};






// 定义一个函数指针类型
typedef int (*func_ptr) (int, int);
// 定义一个函数，接受一个函数指针作为参数
void apply(func_ptr f, int a, int b)
{
    std::cout << f(a, b) << std::endl;
}




class Test
{
public:
    void test()
    {
        // 捕获 this 指针
        auto f = [this] { print(); };
        f();
    }

    void print()
    {
        std::cout << "Hello, from Test!\n";
    }
};




int main(int, char**){
    //lamda表达式的等效形式
    int x = 10;
    auto f = __lambda_1(x); // 创建一个匿名类的对象，等同于下面的lamda表达式
    auto f_lamda = [x](int y) { return x + y; };//这里按值捕获x，注意按值捕获的x在拉姆达表达式中不可修改，因为等效的匿名类的operator()后有const修饰符
    
    
    //lamda表达式和函数指针
    auto mul = [] (int x, int y) -> int { return x * y; };
    func_ptr fp = mul;// 将 Lambda表达式赋值给一个函数指针    
    apply(fp, 3, 4); // 调用函数，传递函数指针

    
    //lamda表达式捕获this指针
    Test t;
    t.test();




}
