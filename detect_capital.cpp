#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int N = word.size();
		int count = 0;//record Capital
		for (int i = 0; i < N; i++) {
			if (word[i] - 'Z' <= 0) count++;
		}
		//GOOD;good;Good
		if (count == N || count == 0 || (count == 1 && word[0] - 'Z' <= 0)) return true;
		else return false;
	}
};