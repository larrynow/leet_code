#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//O(N),greedy solution;
		int N = nums.size();
		int pos = N-1;//pos is the index could get;
		for (int i = N - 2; i >= 0; i--) {

			if (pos - i <= nums[i]) {
				pos = i;
			}
		//Bringing the finish line closer
		}

		return pos == 0;
	}
	//Another forward way : reach = max(i + A[i], reach);
};

//KEEP IT SIMPLE!