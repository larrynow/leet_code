#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans_vec;
		bool self_divisible;
		for (int i = left; i <= right; i++) {
			int num = i;
			int bit_num = -1;
			self_divisible = true;
			while (num != 0 && self_divisible) {
				bit_num = num % 10;
				if (bit_num == 0) {
					self_divisible = false;
					break;
				}
				if ((i % bit_num) != 0) {
					self_divisible = false;
				}
				num = num / 10;
			}
			if (self_divisible) {
				ans_vec.push_back(i);
			}
		}

		return ans_vec;
	}
};
/*
int main() {
	Solution sol = Solution();
	vector<int> ans_vec = sol.selfDividingNumbers(1, 22);
	for (int i = 0; i < ans_vec.size(); i++) {
		cout << ans_vec[i] << endl;
	}
	system("pause");
	return 0;
}
*/
