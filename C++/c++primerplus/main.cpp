#include <bits/stdc++.h>

#include <iostream>
#include <cstring>
#include <iomanip>
#include<vector>
using namespace std;
class A{

    int p;
};
class Person{ // ADT
    public :
        Person():tall(1.8),weight(65.0){};
        Person(long double x,long double y):tall(x),weight(y){};
        virtual ~Person(){};
        virtual void show()=0;
    protected:
        long double tall;
        long double weight;

};
void Person::show()
{cout<<"tall: "<<tall<<"\tweight:"<<weight<<endl;}                                                                                                                                                        
class Woman : public Person
{
    public:
        Woman():Person(),day(1){cout<<&tall<<endl<<&weight<<endl<<&day<<endl;};
        Woman(int d):day(d){};
        Woman(long double x,long double y,int d):Person(x,y),day(d){};
        virtual ~Woman(){};
        virtual void show(){cout<<"tall: "<<tall<<"\tweight:"<<weight<<"\tday:"<<day<<endl;}
    private:
        int day;

};

class Stone
{
public:
    Stone(double wei, int n=0){weight = wei;num = n;cout<<"@@@ construct "<<wei<<"\t"<<n<<endl;}
    Stone(const Stone& s){
        weight = s.weight;
        num = s.num;
        cout<<"copy construct"<<endl;
    }
    ~Stone(){cout<<"deconstruct !!!"<<weight<<"\t"<<num<<endl;}
    void show();
private:
double weight;
int num;
};
void Stone::show(){
    cout<<weight<<"\t"<<num<<endl;
}
// bool get_vector_max()
// write code to check the biggest number in vector

int main()
{
    Stone s1 = 666;
    s1.show();
    cout<<&s1<<endl;
    
    cout<<"after change"<<endl;

    s1.show();
    cout<<&s1<<endl;
    return 0;

}

