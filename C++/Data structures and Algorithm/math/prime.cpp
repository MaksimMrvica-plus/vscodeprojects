#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){ 
    int n,i,j;
    //cin>>n;
    n = 1009; // set to n;
    // 动态数组 存储每一个素数
    vector<int> prime(1); // save all primes from 2 to n;
    prime[0]=0; // prime[0] save cnt;
    // 标记数组，将非素数标记为1，素数为0；
    int *arr = new int[n+1];
    memset(arr,0,sizeof(int)*(n+1));
    
    for(i=2;i<=n;i++){
        if(arr[i]==0){prime.push_back(i);prime[0]++;}//是素数加进去，个数增加；
        for(j=1;j<=prime[0];j++){
            if(i*prime[j]<=n)arr[i*prime[j]]=1;//筛掉
            if(i%prime[j]==0)break; //避免重复
        }
    }
    
    for(i = 1;i<=prime[0];i++)cout<<prime[i]<<endl; //print all primes
    
    cout<<"counts : "<<prime[0]<<endl; // total counts
    return 0;
}