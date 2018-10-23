#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		//reverse(s.begin(), s.end());
		//but reverse is like
		/*while ((first != last) && (first != --last)) {
			std::iter_swap(first, last);
			++first;*/
		for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
			if (i >= j)
				break;
			auto temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}

		return s;
	}
};