#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> ans(A[0].size());
		vector<int> ans_row(A.size());

		for (int j = 0; j < A[0].size(); j++) {
			for (int i = 0; i < A.size(); i++) {
				ans_row[i] = A[i][j];
			}
			ans[j] = ans_row;
		}

		return ans;
	}
};

//int main() {
//	Solution sol = Solution();
//	vector<vector<int>> input_vec = { {1,2,3},{4,5,6},{7,8,9} };
//	vector<vector<int>> ans_vec = sol.transpose(input_vec);
//	for (int i = 0; i < ans_vec.size(); i++) {
//		for (int j = 0; j < ans_vec[0].size(); j++) {
//			cout << ans_vec[i][j]<<' ';
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}