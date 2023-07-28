#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1 = num1.substr(0,num1.size()-1);
        num2 = num2.substr(0,num2.size()-1);
        string real1, imag1, real2, imag2;
        int x1 = 1, y1 = 1, x2 = 1, y2 = 1;

        int i=0;
        while(i<num1.size()){
            if(num1[i]=='+')break;
            real1+=num1[i];
            i++;
        }
        i++;
        while(i<num1.size()){
            imag1+=num1[i];
            i++;
        }
        i=0;
        while(i<num2.size()){
            if(num2[i]=='+')break;
            real2+=num2[i];
            i++;
        }
        i++;
        while(i<num2.size()){
            imag2+=num2[i];    
            i++;
        }
        
        //if(real1[0]=='-')x1=-1;
        //if(imag1[0]=='-')y1=-1;
        //if(real2[0]=='-')x2=-1;
        //if(imag2[0]=='-')y2=-1;
        
        x1 = stoi(real1);
        x2 = stoi(real2);
        y1 = stoi(imag1);
        y2 = stoi(imag2);
        //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
        int x = x1*x2-y1*y2;
        int y = x1*y2+x2*y1;
        //cout<<x<<' '<<y<<endl;
        return to_string(x)+"+"+to_string(y)+'i';
        
        // 字符串中有一个+字符，帮我分割成两个字符串
    }
};
// @lc code=end

