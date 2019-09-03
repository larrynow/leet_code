/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (57.93%)
 * Likes:    971
 * Dislikes: 80
 * Total Accepted:    114.3K
 * Total Submissions: 196.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //Use xor.
        //Step one, find axorb.
        int aXorb = 0;//the result of a xor b.
        //int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());//Function
        for(auto num : nums)
        {
            aXorb ^= num;//the same two xor to 0, so the finally axorb is xor of two distinct nums.
        }
        //Step two, split with last different bit of a,b.
        //aXorb : ...10000 : the rest 4 is same in a and b, differ from 5.
        //-aXorb : ...1000 : this part is same with aXorb, the before is different.(minus the plus one).
        int diffbit = aXorb & (-aXorb);//00010000 : mark a different bit in a and b.
        int a=0, b=0;//group a and b.
        for(auto num : nums)
        {
            if(num & diffbit) a^= num;
            else b^= num;
        }

        return vector<int>{a, b};
    }
};

