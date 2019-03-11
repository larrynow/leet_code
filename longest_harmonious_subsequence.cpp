#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> map;
		for (auto n : nums) {
			map[n]++;//map[n] record how many times a num appears;
			if (map.count(n - 1)) res = max(res, map[n] + map[n - 1]);
			if (map.count(n + 1)) res = max(res, map[n] + map[n + 1]);
		}
		return res;
	}
};