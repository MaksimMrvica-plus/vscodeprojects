#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <thread>
#include <cctype>
using namespace std;


//  ----------------------------------
int findMinDifference(vector<string>& timePoints) {
    ///   12：32
    // H*60 + M
    int n = timePoints.size();
    vector<int> arr;
    
    for(const string& s:timePoints){
        arr.push_back((s[0]-48)*600+(s[1]-48)*60+(s[3]-48)*10+(s[4]-48));
    }
    sort(arr.begin(),arr.end());
    int ans=0x7fffffff;
    int temp = 0;
    for(int i=0;i<n-1;i++){
        temp = arr[i+1]-arr[i];
        if(temp==0)return 0;
        ans = min(ans,temp);
    }
    ans = min(ans,24*60+arr[0]-arr[n-1]);
    return ans;
}
int main(){
    vector<string> timePoints={"00:00","23:59","00:00"};
    cout<<findMinDifference(timePoints);
}
//  ----------------------------------
