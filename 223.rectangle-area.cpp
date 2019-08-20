/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (36.20%)
 * Likes:    264
 * Dislikes: 538
 * Total Accepted:    91.1K
 * Total Submissions: 251.5K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S1 = (C-A) * (D-B);
        int S2 = (G-E) * (H-F);
        if(E>=C || G<=A || F>=D || H<=B) return S1 + S2;// If not overlap;
        int X_L, X_R, Y_U, Y_D;

        // If overlap, calculate edges.
        X_L = max(E, A);
        X_R = min(C, G);
            
        Y_U = min(D, H);
        Y_D = max(B, F);

        return S1 - ((X_R-X_L)*(Y_U-Y_D)) + S2 ;        
    }
};

