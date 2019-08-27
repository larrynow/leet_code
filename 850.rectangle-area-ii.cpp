/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 *
 * https://leetcode.com/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (45.23%)
 * Likes:    201
 * Dislikes: 23
 * Total Accepted:    7.6K
 * Total Submissions: 16.9K
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1,
 * y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner,
 * and (x2, y2) are the coordinates of the top-right corner of the ith
 * rectangle.
 * 
 * Find the total area covered by all rectangles in the plane.  Since the
 * answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * Output: 6
 * Explanation: As illustrated in the picture.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,0,1000000000,1000000000]]
 * Output: 49
 * Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 =
 * (-7)^2 = 49.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= rectangles.length <= 200
 * rectanges[i].length = 4
 * 0 <= rectangles[i][j] <= 10^9
 * The total area covered by all rectangles will never exceed 2^63 - 1 and thus
 * will fit in a 64-bit signed integer.
 * 
 */
class Solution {
public:
    //Mesh count.
    int rectangleArea(vector<vector<int>>& rectangles) {
        int N = rectangles.size();
        set<int> x_set;
        set<int> y_set;
        for(auto rect : rectangles)
        {
            x_set.insert(rect[0]);
            x_set.insert(rect[2]);
            y_set.insert(rect[1]);
            y_set.insert(rect[3]);
        }
        vector<int> x, y;
        unordered_map<int, int> x_index, y_index;
        int index=0;
        for(auto it=x_set.begin();it!=x_set.end();it++)
        {
            x.push_back(*it);
            x_index[*it] = index++;
        }
        index=0;
        for(auto it=y_set.begin();it!=y_set.end();it++)
        {
            y.push_back(*it);
            y_index[*it] = index++;
        }
        //vector<int> x(x_set.begin(), x_set.end());
        //vector<int> y(y_set.begin(), y_set.end());
        int ans = 0;
        //marke for reduplicative count.
        vector<vector<int>> marked = vector<vector<int>>(x.size(), vector<int>(y.size(), 0));
        for(auto rect : rectangles)
        {
            for(int i = x_index[rect[0]];x[i]!=rect[2];i++)
            {
                for(auto j = y_index[rect[1]];y[j]!=rect[3];j++)
                {
                    if(marked[i][j]++ == 0)
                    ans = (ans + (long long)(x[i+1] - x[i])*(y[j+1] - y[j])) % 1000000007;
                }
            }
        }

        return ans;
    }
};

