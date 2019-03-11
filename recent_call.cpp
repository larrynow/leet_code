#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class RecentCounter {
public:
	RecentCounter() {
		int ping(int t);
	}
	queue<int> q;

	int ping(int t) {
		int count = 0;
		q.push(t);
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			if (q.front() < t - 3000)
				q.pop();
			else
				break;
		}
		return q.size();
	}
};