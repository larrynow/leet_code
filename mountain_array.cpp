#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int pre = -1;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] < pre) {
				return i - 1;
			}
			pre = A[i];
		}
	}
};