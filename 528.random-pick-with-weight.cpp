/*
 * Start to use leetcode plugin for vscode.
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

class Solution {
public:
    vector<int> cumsum_w;
    int w_sum = 0;
    Solution(vector<int>& w) {
        for(int wei : w){
            w_sum += wei;
            cumsum_w.push_back(w_sum);
        } 
    }
    
    int pickIndex() {
        int r = rand()%w_sum;
        //upper_bound return the last pos where this value could insert(binary search); 
        int ret = upper_bound(cumsum_w.begin(), cumsum_w.end(), r) - cumsum_w.begin();
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

