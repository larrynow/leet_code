#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std; 

class Solution {
public:
	int reverse(int x) {
		/*long long ans = 0;
		while (x) {
			int i = x % 10;
			ans = ans * 10 + i;
			if (ans > INT_MAX || ans < INT_MIN) {
				return 0;
			}
			x = x / 10;
		}*/
		int ans = 0;
		while (x) {
			int t = ans * 10 + x % 10;//IN PYTHON -3%10=7 !!!
			if (t / 10 != ans) {
				return 0;
			}
			ans = t;
			x /= 10;
		}
		return ans; 
	}
};