#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		//two maker;one for odd in front;one for even follows;Don't need space.(Like use two vec:vec_odd,vec_even;)
		for (int i = 0, j = 1; i <= A.size() - 1 && j <= A.size()-1;) {
			if (A[i] % 2 != 0 && A[j] % 2 == 0) {
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
				i = i + 2;
				j = j + 2;
			}
			else {
				if (A[i] % 2 == 0) {
					i = i + 2;
				}
				if (A[j] % 2 != 0) {
					j = j + 2;
				}
			}
			
		}

		return A;
	}
};

//int main() {
//	vector<int> vec{4,2,5,7};
//	Solution sol = Solution();
//	for (int ans : sol.sortArrayByParityII(vec)) {
//		cout << ans << ' ';
//	}
//
//	system("pause");
//	return 0;
//}