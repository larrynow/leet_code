#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		// If compares, then will calling 1 + 2 + ... + (n - 1) = n(n - 1)/2 times! That's too much

		int* zero_one = new int[2];
		int ans = 0;
		//For any bit
		while (1) {
			int zero_count = 0;
			//if one bit in num is 1,then it will produce n(the number of nums which have a 0 in this bit) Hamming distance;
			zero_one[0] = 0;
			zero_one[1] = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == 0) zero_count++;
				zero_one[nums[i] % 2]++;
				nums[i] = nums[i] >> 1;
			}
			ans += zero_one[0] * zero_one[1];
			if (zero_count == nums.size()) {
				return ans;
			}
		}
	}
};