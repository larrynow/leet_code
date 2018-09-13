class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<str.length();i++){
            if(str.at(i)<='Z'&&str.at(i)>='A'){
                str[i] = char(str.at(i)+('a'-'A'));
            }
        }

        return str;
    }
};