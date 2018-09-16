#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //. ：0 -：1
        string morse_array[26] = {"01","1000","1010","100","0","0010","110","0000","00","0111","101","0100","11","10","111","0110","1101","010","000","1","001","0001","011","1001","1011","1100"};           
		set<string> morse_str_set;//set is undulplicated
        string morse_str_now;
        for(int i=0;i<words.size();i++){
        	morse_str_now = "";
            for(int j=0;j<words[i].length();j++){
                int num = words[i][j] -'a';
                morse_str_now+=morse_array[num];
            }                        
            morse_str_set.insert(morse_str_now);
		}

        return morse_str_set.size();
    }
};

int main(int argc, char *argv[]){
	Solution *sol = new Solution();
	vector<string> vec{"gin", "zen", "gig", "msg"};
	cout << sol->uniqueMorseRepresentations(vec)<<endl;
	
	return 0;
}
