#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	//Just like doing in matrix search;prrof in https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm
	int maxArea(vector<int>& height) {
		int N = height.size();
		int count = 0;
		for (int le = 0, ri = N - 1; le < ri;) {
			if (height[le] < height[ri]) {
				count = max(count, (ri - le)*height[le]);
				le++;
			}
			else {
				count = max(count, (ri - le)*height[ri]);
				ri--;
			}
		}

		return count;
	}
};