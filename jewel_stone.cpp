#include<iostream>
#include<string>

using namespace std;
class Solution{
    public:
    int numJewelsInStones(string J,string S){
        int count = 0;
        for(string::iterator it = S.begin();it!= S.end();it++){
            for(string::iterator it_ = J.begin();it_!= J.end();it_++){
                if(*it-*it_==0)
                    count++;
            }
        }

        return count;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution sol = new Solution();
    cout << sol.numJewelsInStoness('ssaa','a') << endl;
    
    return 0;
}
