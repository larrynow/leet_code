#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int m = -1, n = -1;//record two fruit type;
		int m_tail = -1, n_tail = -1;//record a type's tail position;
		int count = 0;
		int ans = -1;
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] != m && tree[i] != n) {//when meet new type, renew the anterior type and it's position
				count = i - min(m_tail, n_tail);
				m_tail < n_tail ? m = tree[i] : n = tree[i];
				m_tail < n_tail ? m_tail = i : n_tail = i;
			}
			else{
				tree[i] == m ? m_tail = i : n_tail = i;//or just count++;
				count++;
			}
			if (count > ans) {//record the max count;
				ans = count;
			}
		}

		return ans;
	}
};