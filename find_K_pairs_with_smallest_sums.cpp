#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:

	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> ans;
		int M = nums1.size();
		int N = nums2.size();
		
		if (M == 0 || N == 0) return ans;

		//A lambda function;
		auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>  pq(cmp);// reload operator < (pair a, pair b){};
		for (int m = 0; m < M; m++) pq.emplace(m, 0);//emplace (args) construct(args) then push;construct only once;

		while (!pq.empty() && k-- > 0) {
			auto cur = pq.top(); pq.pop();
			int m = cur.first;
			int n = cur.second;
			ans.emplace_back(nums1[m], nums2[n]);//emplace_back;
			//A easy way to travessal a matrix;
			if (n < N - 1) pq.emplace(m, n + 1);
		}
		return ans;
	}
};