#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int length = S.size();
		int count = 0;
		int line = 1;
		for (int i = 0; i < length; i++) {
			count += widths[S[i]-'a'];
			if (count > 100) {
				count = widths[S[i] - 'a'];
				line++;
			}
			if (count == 100) {
				count = 0;
				line++;
			}
		}

		return vector<int> {line, count};
	}
};

//int main() {
//	Solution sol = Solution();
//	vector<int> input_vec = { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
//	vector<int>  ans = sol.numberOfLines(input_vec, "bbbcccdddaaa");
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i]<<' ';
//	}
//
//	system("pause");
//	return 0;
//}