#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int m = nums.size();
		if (m < 4) return ans;
		sort(nums.begin(), nums.end());
		
		//judge if the first two nums i,j to avoid useless loop, pruning ;
		for (int i = 0; i < m - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;//same value, to the last one;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;//break to avoid useless loop;
			if (nums[i] + nums[m - 1] + nums[m - 2] + nums[m - 3] < target) continue;//too small;
			for (int j = i + 1; j < m - 2; j++) {
				if (j > i+1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[m - 1] + nums[m - 2] < target) continue;//too small;
				int left = j + 1;
				int right = m - 1;
				while (left < right) {
					int total = nums[i] + nums[j] + nums[left] + nums[right];
					if (total == target) {
						ans.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
						for (; left < right && nums[left] == nums[left + 1]; left++);//to the last same one;
						for (; left < right && nums[right] == nums[right - 1]; right--);
						left++; right--;//additional operator;
					}
					else if (total < target) left++;
					else right--;
				}
			}

		}

		return ans;
	}
};