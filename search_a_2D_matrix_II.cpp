#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int M = matrix.size();
		if (M == 0) return false;
		int N = matrix[0].size();
		if (N == 0) return false;

		int x = 0, y = N - 1;
		//in every step, the upper-right element is bigger than all the left e's, and is smaller than all the e's below it;
		while (x <= M - 1 && y >= 0) {
			if (target == matrix[x][y]) return true;
			else if (target > matrix[x][y]) x++;
			else y--;
		}

		return false;
	}
};