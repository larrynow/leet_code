#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<vector>

using namespace std; 

/*A DP problem.*/
class Solution {
public:
	int climbStairs(int n) {
		vector<int> vec(n+1, 0);//include vec[n]...
		vec[1] = 1;
		vec[2] = 2;
		int i = 3;
		while (i <= n) {
			vec[i] = vec[i - 1] + vec[i - 2];//For n-step stair, steps could be n-1 step stair get one more step + n-2 step stair get two more.
			i++;
		}

		return vec[n];
	}
};