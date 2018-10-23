#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		//string ans;	 
		auto tmp = s.begin(), pos = s.begin();
		while ( pos != s.end()) {
			if (*pos == ' ') {
				//reverse
				reverse(tmp, pos);
				tmp = pos+1;
			}
			pos++;
		}
		reverse(tmp, s.end());

		return s;
	}
};

//int main() {
//	Solution sol = Solution();
//	string  ans = sol.reverseWords("abc bcd cde def ef");
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}