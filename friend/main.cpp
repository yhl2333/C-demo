#include <iostream>
#include <string>
using namespace std;

class Building;	// 类的前置声明
//成员函数做友元
class BestFriend
{
public:

    BestFriend();
    void visit();
    Building *building;
};


class Building
{
public:
    // 全局函数做友元
    friend void friend1(Building *building);
    //成员函数做友元
    friend void BestFriend::visit();	
    // 类做友元
    friend class GoodGay;

	// Building的构造函数，给成员变量赋初值
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	
	string m_SittingRoom;	// 客厅

private:

	string m_BedRoom;		// 卧室
};

BestFriend::BestFriend(){                    //buidling的初始化要在BestFriend和building之后，不能定义在之内
    building = new Building();
}

void BestFriend::visit()                    //visit函数要定义在building之后，因为如果在之内，那么BestFriend对building的认知仅仅是class Building；并不知道Building的成员变量
{
    cout << "BestFriend 正在访问： " << building->m_SittingRoom << endl;

    cout << "BestFriend 正在访问： " << building->m_BedRoom << endl;
}



//全局函数做友元
void friend1(Building *building)
{
	cout << "全局函数 正在访问：（地址传递） " << building->m_SittingRoom << endl;

	cout << "全局函数 正在访问：（地址传递） " << building->m_BedRoom << endl;
}

//类做友元
class GoodGay
{
public:

    GoodGay(){
        building = new Building();
    }
    void visit(){
        cout << "GoodGay 正在访问： " << building->m_SittingRoom << endl;
        cout << "GoodGay 正在访问： " << building->m_BedRoom << endl;
    }	// 参观函数 访问Building中的属性
    Building *building;
};




int main(int, char**){
    Building* building = new Building();
    friend1(building);
    GoodGay gg;
    gg.visit();
    BestFriend bf;
    bf.visit();
    std::cout << "Hello, from friend!\n";
}
