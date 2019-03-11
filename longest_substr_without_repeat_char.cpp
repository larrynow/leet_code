#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<char> v;
		int max_length = 0;
		for (char c : s) {
			if (find(v.begin(), v.end(), c) == v.end()) {
				v.push_back(c);
			}
				
			else{
				auto first = v.begin();
				while (*first != c) {
					v.erase(first);
					first = v.begin();
				}
				v.erase(first);
				v.push_back(c);
			}
			max_length = max_length > v.size() ? max_length : v.size();
		}		

		return max_length;
	}
};

/*
int main() {
	string s = "pwwkew";
	//string s = "nfpdmpi";
	int ret = Solution().lengthOfLongestSubstring(s);

	string out = to_string(ret);
	cout << out << endl;

	system("pause");
	return 0;
}*/