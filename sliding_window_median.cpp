#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> window(nums.begin(), nums.begin() + k);//a multi set have a balanced binary tree always sorted
		vector<double> ans_vec;
		int siz = nums.size();
		auto mid = next(window.begin(), k / 2);//next,prev moves iterator
		for (int i = k;; i++) {
			ans_vec.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);//if even,go back one position(0 1 2 3) trick:use 1-k%2 judging even or not
			if (i == siz) return ans_vec;
			window.insert(nums[i]);
			if (nums[i] < *mid) {
				--mid;//--mid in case ++mid in next move(means keep mid stil eventually)
			}
			if (nums[i - k] <= *mid)
				++mid;//if the left bound one is smaller than mid,move mid and erase it
			window.erase(window.lower_bound(nums[i - k]));//lower_bound for reduplicated
		}
	}
};
