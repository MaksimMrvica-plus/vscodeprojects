/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp (n);
        int i,j,k;
        for(i=0;i<n;i++)dp[i]=0;
        dp[0] = nums[0];
        for(i=1;i<n;i++){
            dp[i] = max(nums[i],nums[i]+dp[i-1]);
        }
        int maxn = *max_element(dp.begin(),dp.end());
        for(i=0;i<n;i++)cout<<dp[i]<<' ';cout<<endl;
        for(auto x:dp)x= 0;
        dp[0] = nums[0];
        for(i=1;i<n;i++){
            dp[i] = min(nums[i],nums[i]+dp[i-1]);
        }
        int ssum = accumulate(nums.begin(),nums.end(),0);
        int minn = *min_element(dp.begin(),dp.end());
        for(i=0;i<n;i++)cout<<dp[i]<<' ';cout<<endl;
        cout<<maxn<<'\t'<<minn<<'\t'<<ssum<<endl;
        if(minn == ssum)return maxn;
        string s;
        return max(maxn,ssum-minn);
    }
};
// @lc code=end




