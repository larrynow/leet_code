#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int m = nums.size();
		sort(nums.begin(), nums.end());
		int i = 0;
		for (; i < m - 1; i++) {
			int j = i + 1;
			int k = m - 1;
			while (j < k) {
				if (-(nums[i] + nums[j]) == nums[k]) {
					ans.push_back(vector<int> {nums[i], nums[j], nums[k]});
					while (j < k && nums[j] == nums[j + 1]) j++;// if add already move to the last same;
					while (j < k && nums[k] == nums[k - 1]) k--;// then move on
					j++;
					k--;
				}
				else if (-(nums[i] + nums[j]) < nums[k]) k--;
				else j++;

			}
			for (; i < m - 1 && nums[i] == nums[i + 1]; i++);// move i to the last same, will add one after for loop, so each considered i is diff
		}

		return ans;
	}
};