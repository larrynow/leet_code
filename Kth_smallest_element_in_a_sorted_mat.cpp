#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	//Use bi search find k-th smallest
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int N = matrix[0].size();
		int left, right, mid;
		left = matrix[0][0];
		right = matrix[N - 1][N - 1];
		while (left < right) { 
			int count = 0;
			mid = left + (right - left) / 2;
			for (int i = 0; i < N; i++) {
				//count the numbers smaller than mid, judge if target number in the left or right part;
				count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();//upper_bound : find the pos that value >= mid, if not return .end();
			}
			if (k <= count) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

		return left;
	}
};