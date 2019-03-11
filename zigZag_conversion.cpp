#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		char ans[1000];
		int length = s.size();
		if (numRows == 1) {
			return s;
		}
		int numCols;
		int l = length / (numRows + (numRows - 2));
		int r = length % (numRows + (numRows - 2));
		numCols = l * (numRows - 1) + (r > numRows ? r - numRows + 1 : 1);
		vector<vector<char>> vec(numRows,vector<char>(numCols,'#'));
		int i = 0;
		for (int col = 0; col < numCols; col++) {
			if (col % (numRows - 1) == 0) {
				for (int row = 0; row < numRows; row++) {
					if (i == s.size())
						break;
					vec[row][col] = s[i];
					i++;
				}
			}
			else {
				vec[numRows - 1 - (col % (numRows - 1))][col] = s[i];
				i++;
			}
		}

		int j = 0;
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				if (vec[row][col] == '#')
					continue;
				ans[j] = vec[row][col];
				j++;
			}
		}
		ans[j] = '\0';

		return string(ans);
	}
};

//int main() {
//	string s = "Apalindromeisaword, phrase, number, orothersequenceofunitsthatcanbereadthesamewayineitherdirection, withgeneralallowancesforadjustmentstopunctuationandworddividers.";
//	int numRows = 4;
//	string ans = Solution().convert(s, numRows);
//
//	cout << -13%10 << endl;
//	
//	system("pause");
//
//	return 0;
//}