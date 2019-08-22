/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (48.14%)
 * Likes:    1491
 * Dislikes: 47
 * Total Accepted:    69.8K
 * Total Submissions: 144.9K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        //balloons.
        vector<int> balloons(len+2, 0);
        for(int t=1;t<=len;t++)
        {
            balloons[t] = nums[t-1];
        }
        balloons[0] = balloons[len+1] = 1;
        
        vector<vector<int>> dp(len+2, vector<int>(len+2, 0));
        for(int w = 2; w<=len+1;w++)
        {
            for(int i=0;i+w<=len+1;i++)
            {
                int j = i+w;
                for(int t=i+1;t<j;t++)// t:the last balloon to burst. 
                {
                    dp[i][j] = max(dp[i][j], dp[i][t] + dp[t][j] + balloons[i]*balloons[t]*balloons[j]);
                }
            }
        }

        return dp[0][len+1];
    }
};

