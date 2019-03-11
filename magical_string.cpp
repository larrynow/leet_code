#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int magicalString(int n) {
		int count = 0;
		int add = 2;
		string s = "1";
		while (s.size() <= n) {
			s.append(string(*prev(s.end(), add - 1), add));
			if (add == 1) {
				count += add;
				add = 2;
			}
			else {
				add = 1;
			}
		}

		return count;
	}
};