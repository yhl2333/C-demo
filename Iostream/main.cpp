// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//         int i;
//         char str[20];
//         string s1;
//         cout << "请输入一个字符串：";
//         cin >> s1;
//         cout << "s1 = " << s1;
//         cout << "请输入一个整型及一个字符串：";
//         cin >> i >> str;
//         cout << "i = " << i << endl;
//         cout << "str = " << str << endl;
//         char str1[20];
//         cout << "请输入一个字符串：";
//         cin >> str1;
//         cout << "str1 = " << str1 << endl;
//         return 0;
// }


#include <iostream>
#include<fstream>
using namespace std;

int main() {

    //创建文件test.txt并打开
    ofstream outfile("test.txt");
    //向test.txt文件中写入4096个字符’a’
    for(int n=0;n< 20;n++)
    {
        outfile << 'a';
    }
    //暂停，按任意键继续
    system("PAUSE");
    //继续向test.txt文件中写入字符’b’，也就是说，第4097个字符是’b’
    outfile << 'b';
    //暂停，按任意键继续
    system("PAUSE");


}