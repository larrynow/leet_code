/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (45.29%)
 * Likes:    407
 * Dislikes: 89
 * Total Accepted:    23.7K
 * Total Submissions: 52.4K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and
 * attempts to make exactly K moves. The rows and columns are 0 indexed, so the
 * top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below. Each
 * move is two squares in a cardinal direction, then one square in an
 * orthogonal direction.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly K moves or has moved
 * off the chessboard. Return the probability that the knight remains on the
 * board after it has stopped moving.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 * 
 * 
 */
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> moves{{1, 2}, {2, 1}, {1, -2}, {2, -1}, 
                {-1, 2}, {-2, 1}, {-1, -2}, {-2,-1}};
        vector<vector<double>> prob(N, vector<double>(N, 0.0));// The prob of make a move and stiil on board. 
        vector<vector<double>> prob_n(N, vector<double>(N, 1.0));// The prob of make extra move depend on move prob.
        for(int k = 0; k<K;k++)
        {
            for(int i = 0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    double _prob = 0;
                    for(auto move : moves)
                    {
                        int _i = i + move[0];
                        int _j = j + move[1];
                        if(_i >=0 && _i <= N-1 
                        && _j >=0 && _j <= N-1)
                        {
                            _prob += prob_n[_i][_j];
                        }
                    }
                    prob[i][j] = _prob/moves.size();
                }
            }
            prob_n = prob;
        }
        
        return prob_n[r][c];
    }
};

