#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		auto it = minmax_element(nums.begin(), nums.end());//use minmax_lement could get the position of max and min elements;
		/*bucket sort
		 *split the nums into several buckets, the max gap should not be 
		 *smaller than average gap;
		 *the range: max - min
		 *the bucket nums:(max -min)/nums + 1; 
		 */
		int gap = max((*it.second - *it.first)/(n - 1), 1);//n-1 gaps in n nums;
		int bucket_num = (*it.second - *it.first) / gap + 1;//+1 adds the boundary one;
		vector<int> max_in_bucket(bucket_num, INT_MIN);//initializaed as smallest;
		vector<int> min_in_bucket(bucket_num, INT_MAX);

		for (auto itt : nums) {
			int n = (itt - *it.first)/gap;//calculate bucket label; (m-min) / gap;
			if (itt > max_in_bucket[n]) max_in_bucket[n] = itt;
			if (itt < min_in_bucket[n]) min_in_bucket[n] = itt;
		}

		int i = 0;
		int j = i + 1;
		int ans = 0;
		while (i < bucket_num) {
			while (j < bucket_num && max_in_bucket[j] == INT_MIN && min_in_bucket[j] == INT_MAX) j++;//cross one gap
			if (j == bucket_num) break;
			ans = max(ans, min_in_bucket[j] - max_in_bucket[i]);
			i = j;
			j = i + 1;
		}

		return ans;
	}
};
