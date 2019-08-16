/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (51.80%)
 * Likes:    764
 * Dislikes: 47
 * Total Accepted:    55.9K
 * Total Submissions: 108K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> indexs;// Stack stores descend num indexs.
        vector<int> bigger(nums.size(), -1);

        for(int i = 0; i < nums.size()*2; i++)
        {
            auto num = nums[i%nums.size()];
            while (indexs.size() && nums[indexs.top()] < num)
            {
                bigger[indexs.top()] = num;
                indexs.pop();
            }
            if( i < nums.size())
                indexs.push(i);// Only push the first half, rest only for compare.
        }

        return bigger;
    }
};

