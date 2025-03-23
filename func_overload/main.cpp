#include <iostream>

// 重载版本一：两个整数相加
int add(int a, int b) {
    return a + b;
}

// int add(int b, int a) {   //无法重载，因为函数签名是一样的
//     return a + b;
// }

// void add(int b, int a) {   //无法重载，进更改返回值类型无法重载
//     ;
// }

// 重载版本二：三个整数相加
int add(int a, int b, int c) {
    return a + b + c;
}

// 重载版本三：两个浮点数相加
float add(float a, float b) {
    return a + b;
}




int main() {
    std::cout << add(1, 2) << std::endl;  // 3
    
    return 0;
}


