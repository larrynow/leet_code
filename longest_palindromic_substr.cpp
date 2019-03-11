#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		string ans;
		string cur_str_odd;
		string cur_str_even;
		int max_length = 0;

		/*Don't need insert, instead use [low, high] get substr.*/

		/*for case like "aba"*/
		for (int i = 0; i < s.size(); i++) {
			cur_str_odd = s[i];
			for (int dist = 1; i - dist >= 0 && (i + dist) <= (s.size() - 1); dist++) {
				if (s[i - dist] == s[i + dist]) {
					cur_str_odd.insert(cur_str_odd.begin(), s[i - dist]);
					cur_str_odd.insert(cur_str_odd.end(), s[i + dist]);
					if (dist * 2 + 1 > max_length) {
						max_length = dist * 2 + 1;
						ans = cur_str_odd;
					}
				}
				else
					break;

			}
		}
		/*for case like "abb"*/
		for (int i = 0; i < s.size(); i++) {
			cur_str_even = "";
			for (int dist = 1; i - (dist - 1) >= 0 && (i + dist) <= (s.size() - 1); dist++) {
				if (s[i - (dist - 1)] == s[i + dist]) {
					cur_str_even.insert(cur_str_even.begin(), s[i - (dist - 1)]);
					cur_str_even.insert(cur_str_even.end(), s[i + dist]);
					if (2 * dist > max_length) {
						max_length = 2 * dist;
						ans = cur_str_even;
					}
				}
				else
					break;
			}
		}
		if (max_length == 0)
			ans = s[0];

		return ans;

	}
	
};

/*
int main() {
	string ret = Solution().longestPalindrome("cbaabd");

	string out = (ret);
	cout << out << endl;

	system("pause");

	return 0;
}*/