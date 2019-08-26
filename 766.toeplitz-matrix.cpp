/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (62.33%)
 * Likes:    674
 * Dislikes: 67
 * Total Accepted:    67.1K
 * Total Submissions: 107.6K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same element.
 * 
 * Now given an M x N matrix, return True if and only if the matrix is
 * Toeplitz.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * [1,2,3,4],
 * [5,1,2,3],
 * [9,5,1,2]
 * ]
 * Output: True
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * [1,2],
 * [2,2]
 * ]
 * Output: False
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * matrix will be a 2D array of integers.
 * matrix will have a number of rows and columns in range [1, 20].
 * matrix[i][j] will be integers in range [0, 99].
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the matrix is stored on disk, and the memory is limited such that
 * you can only load at most one row of the matrix into the memory at once?
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 * 
 * 
 */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(M==0||M==1) return true;
        int N = matrix[0].size();

        for(int i=0;i<M-1;i++)
        {
            for(int j=0;j<N-1;j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }

        return true;
        /*Stupid
        vector<vector<int>> marked(M, vector<int>(N, 0));
        deque<pair<int, int>> current;
        deque<pair<int, int>> next;
        current.push_back(make_pair(0, N-1));//the right bottom one.
        while(!current.empty())
        {
            auto cur = current.front();
            current.pop_front();
            if(cur.first+1<M && !marked[cur.first + 1][cur.second])
            {
                next.push_back(make_pair(cur.first + 1, cur.second));
                marked[cur.first + 1][cur.second] = 1;
            }
            if(cur.second>=1 && !marked[cur.first][cur.second-1])
            {
                next.push_back(make_pair(cur.first, cur.second-1));
                marked[cur.first][cur.second-1] = 1;
            }
            if(current.empty())
            {
                if(next.empty()) return true;// left bottom.
                auto val = matrix[next[0].first][next[0].second];
                for(auto i : next)
                {
                    if(matrix[i.first][i.second] != val)
                        return false;
                }
                current = next;
                next.clear();
            }
        }

        return true;
        */
    }
};

