/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */
#include<vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int rows = A.size()+1;
        int cols = B.size()+1;
        int ans = 0;
        vector<vector<int>> c(rows, vector<int>(cols, 0));
        for(int i = 1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(A[i-1]==B[j-1]){
                    c[i][j] = c[i-1][j-1]+1;
                    ans = (c[i][j] > ans ? c[i][j] : ans);
                }
            }
        }

        return ans;
    }
};

