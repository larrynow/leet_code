#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<string> vec_1{"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> vec_10{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> vec_100{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};

        //string(2,'c');
        return string((num/1000),'M')+vec_100[num%1000/100]+vec_10[num%100/10]+vec_1[num%10];//Note string("M",2) makes it length 2;
    }
};