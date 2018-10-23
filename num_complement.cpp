#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int bit_num, ans = 0;
		int times = 1;
		while (num != 0) {
			bit_num = num % 2;
			num = num / 2;
			ans += (1 - bit_num)*times;
			times *= 2;
		}

		return ans;
	}
};
//
//int main() {
//	Solution sol = Solution();
//	cout<<sol.findComplement(5)<<endl;
//
//	system("pause");
//	return 0;
//}