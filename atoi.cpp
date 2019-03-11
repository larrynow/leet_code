#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long result = 0;
		int indicator = 1;
		int i = str.find_first_not_of(' ');//use find_first_not_of
		if (i == -1)//find_first_not_of returns -1 if input does not match, like "    "
			return 0;
		//str[i] could be '+' or '-'
		if (str[i] == '-' || str[i] == '+')
			indicator = (str[i++] == '+' ? 1 : -1);
		while (str[i] >= '0' && str[i] <= '9') {//use isdigit()~
			result = result * 10 + (str[i]- '0');

			//judge the num early in case the num is real big and "long" can't handle (num>>long)
			if (result  > INT_MAX )//int : -2147483648 <-> 2147483647, judge [-2147483647, 2147483647];
				return indicator == 1 ? INT_MAX : INT_MIN;
			i++;
		}
	
		return result * indicator;

	}
};