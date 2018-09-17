class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i < A.size();i++) {
			for (int j = 0; j < (A[i].size()+1)/2; j++) {
				int temp = A[i][j];
				A[i][j] = (A[i][(A[i].size() - j - 1)] == 0);
				A[i][(A[i].size() - j - 1)] = (temp == 0);
			}
		}

		return A;
	}
};