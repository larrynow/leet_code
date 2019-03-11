#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
	/*
	 * Use priority_queue; actually bsed on dijkstra;
	 * each value in the queue means a move to choice, pq makes it possible to go back and find a min value namely a earliest time which this path cost;
	 * priority_queue : priority_queue<T, vector<T>, operator< > by deafault;
	 * Default : operator< , big top heap, decrease order, max in top;
	 * Reverse it so that smallest in top : bool operator< (const T &d) const {return t > d.t;}
	 */

	struct T {
		int x, y, t;
		T (int a, int b, int c) : x(a), y(b), t(c) {}
		bool operator< (const T &d) const { return t > d.t; }//Reverse it so that smallest value will in top of priority_queue;
	};

	int swimInWater(vector<vector<int>>& grid) {
		//std::priority_queue<T, std::vector<T>, std::function<bool(T, T)>> pq([](const auto& t1, const auto& t2) { return std::get<0>(t1) > std::get<0>(t2); });
		priority_queue<T> pq;//use a priority_queue;//priority_queue<int, vector<int>, greater<int>> pq; deafault bigger top heap, use greater to be smallest top;
		int N = grid[0].size();
		int ans = 0;
		vector<vector<int>> seen(N, vector<int>(N, 0));
		vector<vector<int>> dir({ {0,1},{0,-1},{1,0},{-1,0} });//clever way to use dir vector define a move
		
		seen[0][0] = 1;//Note to mark [0][0] first;
		pq.push(T(0, 0, grid[0][0]));

		while (true) {
			auto curr = pq.top();//smallest in the top;
			pq.pop();
			ans = max(ans, curr.t);
			if (curr.x == N - 1 && curr.y == N - 1) return ans;//to the end;
			for (auto &d : dir) {
				int i = curr.x + d[0], j = curr.y + d[1];
				if (i <= N - 1 && i >= 0 && j >= 0 && j <= N - 1 && !seen[i][j]) {
					pq.push(T(i, j, grid[i][j]));
					seen[i][j] = 1;
				}
			}

		}
	}
};