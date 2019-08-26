/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 *
 * https://leetcode.com/problems/find-the-shortest-superstring/description/
 *
 * algorithms
 * Hard (38.61%)
 * Likes:    185
 * Dislikes: 54
 * Total Accepted:    5.5K
 * Total Submissions: 14.1K
 * Testcase Example:  '["alex","loves","leetcode"]'
 *
 * Given an array A of strings, find any smallest string that contains each
 * string in A as a substring.
 * 
 * We may assume that no string in A is substring of another string in A.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["alex","loves","leetcode"]
 * Output: "alexlovesleetcode"
 * Explanation: All permutations of "alex","loves","leetcode" would also be
 * accepted.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
 * Output: "gctaagttcatgcatc"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 1 <= A[i].length <= 20
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        // State Reduction DP.
        /** consider each string as a city in TSp, the overlap of two strings is consider as path between them. */
        int len = A.size();
        int n =len;

        vector<vector<int>> overlaps(len, vector<int>(len));// two string overlap size.

        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                int m = min(A[i].size(), A[j].size());
                for(int k=m;k>=0;k--)//overlap with k char.
                {
                    if(A[i].substr(A[i].size()-k) == A[j].substr(0,k))// i(len-k, len), j(0, k), i + j.
                    {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }

        vector<vector<int>> dp(1<<len, vector<int>(len, 0));// dp[i][j] : overlap of nodeset i ending with j.
        vector<vector<int>> parent(1<<len, vector<int>(len,-1));// parent[i][j] : the pre string before j.

        for(int i=1;i<(1<<len);i++)
        {
            for(int j=0;j<len;j++)
            {
                if((i&(1<<j))>0)//j in set i.
                {
                    int prev = i-(1<<j);// prev set without j.
                    // int prev = i^(1<<j);// xor.
                    if(prev == 0)// i only have j.
                    continue;
                    for(int k=0;k<len;k++)
                    {
                        if((prev&(1<<k))>0)// if k in prev.
                        {
                            int val = dp[prev][k] + overlaps[k][j];
                            if(val > dp[i][j])// find a smaller length.
                            {
                                dp[i][j] = val;
                                parent[i][j] = k;
                            }
                        }
                    }
                }
            }
        }

        vector<int> perm;
        vector<bool> seen(n);
        int mask = (1<<n) - 1;// full set.
        
        int p = 0;//find last string.
        for (int i = 0; i < n; ++i) {
            if (dp[(1<<n) - 1][i] > dp[(1<<n) - 1][p]) {// use dp[fullset][i] find last string.
                p = i;
            }
        }
        
        // use parent get each string backward.
        while (p != -1) {
            perm.push_back(p);
            seen[p] = true;
            int p2 = parent[mask][p];
            mask ^= (1<<p);// remove string one by one.
            p = p2;
        }
        
        // reverse.
        reverse(perm.begin(), perm.end());
        
        // string with out overlap.
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                perm.push_back(i);
            }
        }
        
        string ans = A[perm[0]];
        for (int i = 1; i < n; ++i) {
            int overlap = overlaps[perm[i - 1]][perm[i]];// get overlap size.
            ans += A[perm[i]].substr(overlap);// ad it.
        }
        
        return ans;
    }
};

