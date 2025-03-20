#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Shoes{
public:
    virtual void product() = 0;
};

class Clothes{
public:
    virtual void product() = 0;
};



class NikeShoes: public Shoes{
public:
    virtual void product() {
        std::cout<<"生产耐克鞋"<<std::endl;
    }
    

};

class AdiShoes: public Shoes{
public:
    virtual void product() {
        std::cout<<"生产阿迪鞋"<<std::endl;
    } 

};


class NikeClothes: public Clothes{
public:
    virtual void product(){
        std::cout<<"生产耐克衣服"<<std::endl;
    }
};

class AdiClothes: public Clothes{
public:
    virtual void product(){
        std::cout<<"生产阿迪衣服"<<std::endl;
    }
};


template <class ProductType_t>
class IProductRegister{

public:
    virtual ProductType_t* Create_Product()= 0;


};


template <class ProductType_t>
class Factory
{
public:

    static Factory<ProductType_t>& instance()
    {
        static Factory<ProductType_t> fac;
        return fac;
    }

    void fac_regist(IProductRegister<ProductType_t>* iter,string name){

        m_ProductRegistry[name] = iter;


    }

    ProductType_t* get_product(string name){

        if (m_ProductRegistry.find(name)!=m_ProductRegistry.end())
            return m_ProductRegistry[name]->Create_Product();
        else
            std::cout<<"没有注册过该商品"<<std::endl;

        return nullptr;

    }


private:

    std::map<std::string, IProductRegister<ProductType_t> *> m_ProductRegistry;

};


template <class ProductType_t, class Product> //这里ProductType_t是Product的基类
class ProductRegister: public IProductRegister<ProductType_t> {
public:

    ProductRegister(std::string name)
    {
        Factory<ProductType_t>::instance().fac_regist(this,name);
    }

    virtual ProductType_t* Create_Product() {

        return new Product();
    }
};























