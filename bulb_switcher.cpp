#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		/*
		 *For each step:
		 *for (int step = 1; step <= n; step++) {
			for (int i = 1; i <= n; i ++) {
				if (i%step==0)
					vec[i] = !vec[i];
		 *bulb i switches at step m when m is fatoc of i(i%m==0)
		 *num i has odd factors when i = x*x, so bulb i will be on
		 *the acount of numbers = x*x smaller than n is sqrt(n);
		 */
		return sqrt(n);
	}
};