/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.13%)
 * Likes:    806
 * Dislikes: 116
 * Total Accepted:    378.2K
 * Total Submissions: 711.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
// Hash
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if(s.size()!=t.size()) return false;
        int length = s.size();
        for(int i = 0;i<length;i++)
        {
            map[s[i]]++;
            map[t[i]]--;
        }

        for(auto item : map)
        {
            if(item.second!=0)
                return false;
        }

        return true;
    }
};

// Another way : sort.
