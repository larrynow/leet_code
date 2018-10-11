#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int pos = 0;
		int temp;
		for (auto it = A.begin(); it != A.end(); it++) {
			if (*it % 2 == 0) {
				temp = A[pos];
				A[pos] = *it;
				*it = temp;
				pos++;
			}

		}

		return A;
	}
};