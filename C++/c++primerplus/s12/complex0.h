#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
class Complex
{
private:
    int real;
    int imaginary;  
public:
    Complex(){};
    Complex(int r,int i);
    ~Complex(){};
    Complex operator+(Complex&b);
    Complex operator-(Complex&b);
    Complex operator*(Complex&b);
    Complex operator~();
    friend Complex operator*(Complex&a,int b);
    friend Complex operator*(int b,Complex&a);
    friend istream& operator>>(istream&os,Complex&com);
    friend ostream& operator<<(ostream&os,Complex&com);

};
