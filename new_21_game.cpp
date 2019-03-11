#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	double new21Game(int N, int K, int W) {
		if (K == 0 || N >= K + W - 1) {//if N = K+W-1, when get K-1, next draw can't make it bigger than N absolutely;
			return 1.0;
		}
		//p_get(N) is the probability to get score N; 
		/*
		 *for p_get, each p_get(i) equals (p_get(i-W)+...+p_get(i-1))/W, 
		 *cause when we get i-W point, draw number W could get i points, etc.
		 *usr p_sum to record;
		 */
		vector<double> p_get(N + 1, 0.0);
		double p_sum = 1.0;//the first W p_get is 1/W
		double ans = 0.0;//ans = p_get(K)+p_get(K+1)+...+p_get(N);

		p_get[0] = 1.0;

		//loop to calculate p_get(i);
		for (int i = 1; i <= N; i++) {
			p_get[i] = p_sum / W;
			if (i < K) {
				p_sum += p_get[i];
			}
			else {
				ans += p_get[i];//ans = p_get(K)+p_get(K+1)+...+p_get(N);
			}
			if (i - W >= 0) {
				p_sum -= p_get[i - W];//make sure p_sum only record last W p_get(i); NOTE p_sum is initialized as 1, (taken as p_get(0)) 
				//so we must remove this part when i >= W, cause p_get(W+1) won't take just one draw(p_get(1) can got from p_get(0) by one draw, p_get(11) can't, so remove p_get(0));
			}
		}

		return ans;
	}
};

/*
int main() {
	int num = 1;
	double ans = Solution().new21Game(21,17,10);
	cout << ans << endl;

	system("pause");
}*/