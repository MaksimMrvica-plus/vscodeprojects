/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int maxn = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=maxn){
                if(nums[i]*2>maxn)return -1;
            }
            else 
            ans = i;
        }
        return ans;
    }
};
// @lc code=end

