#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		/*BFS : change the problem to be a bfs problem;
		 *each num[i] have an expanding range;
		 *let the nums under range to be in the same level;
		 *then levels is exactly the steps;
		 */
		int i = 0;
		int cur_range = 0;
		int next_range = 0;
		int levels = 0;
		if (nums.size() == 1) return 0;
		while (true) {
			levels++;
			for (; i <= cur_range; i++) {
				next_range = max(next_range, nums[i] + i);
				if (next_range >= nums.size() - 1) return levels;
			}
			cur_range = next_range;
			//finish in an expanding range, step into another level;
		}
		
		return -1;
	}
};