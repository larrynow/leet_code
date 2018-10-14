#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int ans = *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) - (2 * K);
		return  ans > 0 ? ans : 0;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> input_vec = { 1,3,6 };
	int  ans = sol.smallestRangeI(input_vec,3);
	cout << ans << endl;

	system("pause");
	return 0;
}