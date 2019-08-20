/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (58.30%)
 * Likes:    724
 * Dislikes: 87
 * Total Accepted:    54.1K
 * Total Submissions: 92.7K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 * 
 * 
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * Note:
 * 
 * 
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 * 
 * 
 */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        transLetter(0, S, ans);

        return ans;
    }

    void transLetter(int pos, string S, vector<string> &ans)
    {
        // Put to ans at end.
        if(pos == S.size())
        {
            ans.push_back(S);
            return;
        }
        transLetter(pos + 1, S, ans);
        if(isalpha(S[pos]))
        {
            S[pos] = (S[pos] ^ 32);// +- 32 to transform letter.
            transLetter(pos+1, S, ans);
        }

    }
};

