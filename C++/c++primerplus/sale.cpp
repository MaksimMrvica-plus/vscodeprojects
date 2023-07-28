#include <iostream>
#include <algorithm>
#include "sale.h"
namespace SALES
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::max;
    using std::min;
    void setSales(Sales &s, const double ar[], int n)
    {
        // 初始化
        for(int i=0;i<QUARTERS;i++)s.sales[i]=0;
        s.average = 0;
        // 数组为空时
        if(n==0){
            s.max = 0;
            s.min = 0;
            return ;
        }
        // 数组非空时
        s.max = ar[0];
        s.min = ar[0];
        int less = min(QUARTERS, n);
        for (int i = 0; i < less; i++)
        {
            s.sales[i] = ar[i];
            s.max = max(ar[i],s.max);
            s.min = min(ar[i],s.min);
            s.average+=ar[i];
        }
        s.average/=less;
    }
    void setSales(Sales &s) {
        // 初始化
        int i=0,n=0;
        s.average = 0;
        while(n<QUARTERS){
            cout<<"enter sale#"<<n+1<<" : ";
            cin>>s.sales[n];
            n++;
        }
        s.max = s.sales[0];
        s.min = s.sales[0];
        for (i = 0; i < QUARTERS; i++)
        {
            s.max = max(s.sales[i],s.max);
            s.min = min(s.sales[i],s.min);
            s.average+=s.sales[i];
        }
        s.average/=QUARTERS;
    }
    void showSales(const Sales &s) {
        for(int i=0;i<QUARTERS;i++){
            if(s.sales[i]==0)break;
            cout<<"sale #"<<i+1<<" : "<<s.sales[i]<<endl;
        }
        cout<<"max : "<<s.max<<endl;
        cout<<"min : "<<s.min<<endl;
        cout<<"average : "<<s.average<<endl;
    }
}
