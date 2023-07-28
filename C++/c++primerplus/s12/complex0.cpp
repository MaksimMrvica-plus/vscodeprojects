#include<iostream>

#include "complex0.h"


Complex::Complex(int r,int i) 
{
    this->real = r;
    this->imaginary = i;
}

Complex Complex::operator+(Complex&b)
{
    int rea = this->real + b.real;
    int ima = this->imaginary+b.imaginary;
    return Complex(rea,ima);
}
Complex Complex::operator-(Complex&b)
{
    int rea = this->real - b.real;
    int ima = this->imaginary - b.imaginary;
    return Complex(rea,ima);
}
Complex Complex::operator*(Complex&b)
{
    int rea = this->real*b.real - this->imaginary*b.imaginary;
    int ima = this->real*b.imaginary + this->imaginary*b.real;
    return Complex(rea,ima);
}
Complex operator*(Complex&a ,int b)
{
    int rea = a.real * b;
    int ima = a.imaginary * b;
    return Complex(rea,ima);
}
Complex Complex::operator~()
{
    return Complex(this->real,-this->imaginary);
}

Complex operator*(int b,Complex&a)
{
    int rea = a.real * b;
    int ima = a.imaginary * b;
    return Complex(rea,ima);
}

istream& operator>>(istream&os,Complex&com){
    int a,b;
    cout<<"real: ";
    cin>>a;
    cout<<"imaginary: ";
    cin>>b;
    com.real = a;
    com.imaginary = b;
    return os;
}
ostream& operator<<(ostream&os,Complex&com)
{
    os << "(" <<com.real << "+" <<com.imaginary <<"i)"<<endl;
    return os;
}