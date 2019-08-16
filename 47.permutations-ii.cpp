/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    // A reverse of sort.
    void recursion(int start, vector<int> arr, vector<vector<int>>& ans)
    {
        int end = arr.size()-1;
        if(start == end) ans.push_back(arr);// Finally push an ans.
        else
        {
            for(int i = start; i<=end;i++)// Each step construct an ans, let start alone.
            {
                if(arr[i] != arr[start] || i == start)// i==start save an ans.
                {
                    swap(arr[start], arr[i]);
                    recursion(start + 1, arr, ans);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        recursion(0, arr, ans);

        return ans;
    }

    
};

