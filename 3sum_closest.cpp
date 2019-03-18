#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int gap = INT_MAX;
		int ans;
		int m = nums.size();
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < m - 1; i++) {
			int j = i + 1;
			int k = m - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum > target) k--;//according to the comparison between sum and target, move the pointer// 
				else if (sum < target) j++;
				else return target;
				if (max(sum, target) - min(sum, target) < gap) {//when gap is smaller, update;
					gap = max(sum, target) - min(sum, target);
					ans = sum;
				}
			}
		}

		return ans;
	}
};
