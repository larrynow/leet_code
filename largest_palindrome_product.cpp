#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int largestPalindrome(int n) {
		//specialy for n=1
		if (n == 1) return 9;

		int upper_limit = pow(10, n) - 1;
		//from 9999 to 999
		for (int i = upper_limit; i > upper_limit / 10; i--) {
			//get a num that is a palindrome
			string s = to_string(i);
			reverse(s.begin(), s.end());
			string value = to_string(i) + s;
			long long p = stoll(value);
			//judge if this palindrome can be got by x, x couldn't smaller than p^1/2.
			for (long long x = upper_limit; x*x >= p; x--) {
				if (p%x == 0) {
					/*cout << p << endl;
					cout << x << endl;
					cout << p / x << endl;*/
					return p % 1337;
				}
			}
		}

		return 0;
	}
};


//int main() {
//	Solution sol = Solution();
//	cout << sol.largestPalindrome(6) << endl;
//	//cout << << endl;
//
//	system("pause");
//	return 0;
//}