/*
 * @lc app=leetcode.cn id=2771 lang=cpp
 *
 * [2771] 构造最长非递减子数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
/*
7 10 8 1 1 9 8 6 8 3 
9 5 2 4 5 6 4 10 4 6 

7 5 2 4 5 6 8 10 4 6

7 5 2 4 5 6 4 6 4 3
9 5 2 4 5 6 4 10 4 6

7 10 8 1 1 9 8 6 8 3 
9 5 2 4 5 6 4 10 4 6 

1 2 2 1 2 4 5 1 2 1
1 1 1 2 3 4 1 6 1 2
1、定义 dp1[i] 表示以 nums1[i] 结尾的最长非递减子数组长度；
2、定义 dp2[i] 表示以 nums2[i] 结尾的最长非递减子数组长度；
3、递推如果后面的数字不小于前面则可以拼接;
*/
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        //vector<int > dp1(n,1),dp2(n,1);
        int max1=1,max2=1;
        int dp1 = 1,dp2 = 1;
        int dp3 = 1,dp4 = 1;

        //dp1[0]=1,dp2[0]=1;
        int i,j,k;
        int a,b,c,d;
        for(i=1;i<n;i++)
        {
            a = nums1[i-1];
            b = nums1[i];
            c = nums2[i-1];
            d = nums2[i];
            if(b>=a && b>=c)dp2=1+max(dp1,dp3);
            else if(b>=a)dp2=1+dp1;
            else if(b>=c)dp2=1+dp3;

            if(d>=a && d>=c)dp4=1+max(dp1,dp3);
            else if(d>=a)dp4=1+dp1;
            else if(d>=c)dp4=1+dp3;

            max1 = max(max1,dp2);
            max2 = max(max2,dp4);

            dp1 = dp2;
            dp3 = dp4;
            dp2 = 1;
            dp4 = 1;
        }
        return max(max1,max2);
    }
};
// @lc code=end

/*


*/