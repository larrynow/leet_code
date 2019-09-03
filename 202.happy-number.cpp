/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (46.25%)
 * Likes:    983
 * Dislikes: 255
 * Total Accepted:    257.9K
 * Total Submissions: 557.3K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */
//Another way : Floyd Cycle detection algorithm.
class Solution {
public:
    bool isHappy(int n) {
        /*
        int num = n;
        unordered_set<int> set;
        set.insert(n);
        while(1)
        {
            num = happy(num);
            if(num==1) return true;
            if(set.count(num)) break;
            set.insert(num);
            cout<<num<<endl;
        }

        return false;
        */
       int fast,slow;//two point with different speed(finally met means a circle.)
       fast = slow = n;
       do{
           slow = happy(slow);//each time 1.
           fast = happy(fast);
           fast = happy(fast);//each time 2.
       }while(slow!=fast);
       if(slow==1) return true;
       else
       {
           return false;
       }
       
    }

    int happy(int n)
    {
        int rest = n;
        int sum=0;
        while(rest!=0)
        {
            int digit = rest%10;
            rest = rest/10;
            sum+=(digit*digit);
        }

        return sum;
    }
};

