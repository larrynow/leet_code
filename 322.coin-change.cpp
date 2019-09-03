/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (31.53%)
 * Likes:    2140
 * Dislikes: 84
 * Total Accepted:    233.8K
 * Total Submissions: 739.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto coin : coins)
        {
            for(int i=0;;i++)
            {
                long long merge_amount = i+coin;
                if(merge_amount>amount) break;
                if(dp[i]!=INT_MAX )//i+amount is makeable.
                    dp[merge_amount] = min(dp[merge_amount], dp[i]+1);
            }
            
        }

        return dp[amount]!=INT_MAX ? dp[amount] : -1;
    }
};

