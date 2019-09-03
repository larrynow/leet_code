/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (45.27%)
 * Likes:    226
 * Dislikes: 81
 * Total Accepted:    11.3K
 * Total Submissions: 25K
 * Testcase Example:  '1'
 *
 * Given a function rand7 which generates a uniform random integer in the range
 * 1 to 7, write a function rand10 which generates a uniform random integer in
 * the range 1 to 10.
 * 
 * Do NOT use system's Math.random().
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: [7]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: [8,4]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: [8,1,10]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * rand7 is predefined.
 * Each testcase has one argument: n, the number of times that rand10 is
 * called.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 * 
 * 
 * 
 * 
 * 
 */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // First let space of rand7 bigger than rand10.
        // Like pick up a item in 2D-array,
        //[[1,2,3,4,5,6,7],
        // [8,9,10,11,12,13, 14],
        // ...
        // [42, ... 48]]
        // a = rand7()-1 for picking row, b = rand7() for picking col, is uniform.
        int ans = 100;
        while(ans>40)
            ans = (rand7()-1) * 7 + rand7();// get uniform of [1,...,49].
        
        ans = ans%10+1;
        
        return ans;
    }
};

