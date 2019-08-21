/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int len = stones.size();
        if((len-1)%(K-1)!=0) return -1;
        // If len-1 stones can be split into some k-1-size pile, 
        // then each pile can merge with the rest one stone as a new stone. 
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(len+1, vector<int>(K+1, 0)));
        vector<int> pre_sum(len+1, 0);
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=len;j++)
            {
                for(int k =1;k<=K;k++)
                {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        // Cost to merge a pile as one is 0.
        for(int i=1;i<=len;i++)
        {
            dp[i][i][1] = 0;
        }
        // The sum of pre n stones.
        for(int i=1;i<=len;i++)
        {
            pre_sum[i] = pre_sum[i-1] + stones[i-1];
        }

        for(int l=2;l<=len;l++)// The length of each segment.
        {
            for(int i=1;i<=len-l+1;i++)
            {
                int j = i + l -1;// Cut between i and i+l-1;
                for(int k = 2; k<=K;k++)// To spilt this segment as k parts.
                {
                    for(int t = i;t<j;t++)// Cut at t, and merge[i, j] as k parts equls merge[i,t] as k-1 and merge[t+1, j] as one.
                    {
                        if(dp[i][t][k-1]==INT_MAX || dp[t+1][j][1]==INT_MAX)
                        continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i][t][k-1]+dp[t+1][j][1]);
                    }
                    if(dp[i][j][K]==INT_MAX)
                    continue;
                    dp[i][j][1] = dp[i][j][K] + pre_sum[j] - pre_sum[i-1];// K->1, only exactly K pile considered in merged into one.
                }
                
            }
        }

        return dp[1][len][1];
    }
};

