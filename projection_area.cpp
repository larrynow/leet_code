#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int count = 0;
		int size = grid.size();
		vector<int> max_in_col(size);
		for (int i = 0; i < grid.size(); i++) {
			count += *max_element(grid[i].begin(),grid[i].end());
			for (int j = 0; j < grid[i].size(); j++) {
				if (max_in_col[j] < grid[i][j]) {
					max_in_col[j] = grid[i][j];
				}
				if (grid[i][j] != 0) {
					count++;
				}
			}
		}

		for (int i = 0; i < max_in_col.size(); i++) {
			count += max_in_col[i];
		}

		return count;
	}
};

//int main() {
//	Solution sol = Solution();
//	vector<vector<int>> input_vec = { {1,2},{3,4} };
//	int ans = sol.projectionArea(input_vec);
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}