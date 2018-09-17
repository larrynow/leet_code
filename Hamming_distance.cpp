class Solution {
public:
	// 001010111000 <=== num%2
	int hammingDistance(int x, int y) {
		int count = 0;
		for (int pos = 31; pos >= 0; pos--) {
			if((x % 2)!= (y % 2))
				count++;
			x = x / 2;
			y = y / 2;
		}

		return count;
	}
};