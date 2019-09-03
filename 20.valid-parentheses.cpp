/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.10%)
 * Likes:    3266
 * Dislikes: 154
 * Total Accepted:    673.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s)
        {
            //For left part, mark it.
            if(c=='(')
            {
                st.push(')');
            }
            else if(c=='[')
            {
                st.push(']');
            }
            else if(c=='{')
            {
                st.push('}');
            }
            else//for right part.
            {
                if(st.empty() || c!=st.top())//unmatch.
                    return false;
                else
                {
                    st.pop();
                }
                
            }
            

        }

        return st.empty();
    }
};

