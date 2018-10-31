#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {

		//This is a bad solution cause time complexity is O(n^2).
		/*vector<int> ans_vec;
		int dist = 1;
		int pos = S.find(C);
		S[pos] = 0;
		int last_pos;
		for (int i = pos - 1; i >= 0; i--) {
			S[i] = dist++;
		}
		while (S.find(C) != string::npos) {
			last_pos = pos;
			pos = S.find(C);
			S[pos] = 0;
			dist = 1;
			for (int i = last_pos + 1, j = pos - 1; i <= j; i++, j--) {
				S[i] = S[j] = dist;
				dist++;
			}
		}
		dist = 1;
		for (int i = pos + 1; i <= S.size() - 1; i++) {
			S[i] = dist++;
		}
		for (auto s : S) {
			ans_vec.push_back(s);
		}
		
		return ans_vec;*/
	
		//Or we could use two for front and back: if (S[i] == C) pos = i; res[i] = min(res[i], abs(i - pos));O(n)
		int length = S.size();
		vector<int> ans_vec(length, length);
		int pos = -length;

		//Front to make the pos's right side.
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == C) {
				pos = i;
			}
			ans_vec[i] = min(ans_vec[i], abs(i - pos));
		}

		//Back to make the pos's left side.s
		for (int j = length-1; j >= 0; j--) {
			if (S[j] == C) {
				pos = j;
			}
			ans_vec[j] = min(ans_vec[j], abs(j - pos));

		}

		return ans_vec;
	}
};