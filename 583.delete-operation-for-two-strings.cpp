/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (45.43%)
 * Likes:    759
 * Dislikes: 20
 * Total Accepted:    34.6K
 * Total Submissions: 76.1K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
// Make LCS to construct.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len = max(word1.size(), word2.size()) + 1;
        vector<vector<int>> length(len, vector<int>(len, 0));

        for(int X = 1; X < word1.size()+1;X++)
        {
            for(int Y = 1; Y < word2.size()+1; Y++)
            {
                if(word1[X-1] == word2[Y-1])
                {
                    length[X][Y] = length[X-1][Y-1] + 1;
                }
                else if(length[X-1][Y] > length[X][Y-1])
                {
                    length[X][Y] = length[X-1][Y];
                }
                else
                {
                    length[X][Y] = length[X][Y-1];
                }
            }
        }
        
        return word1.size()+word2.size() - 2*length[word1.size()][word2.size()];
    }
};

