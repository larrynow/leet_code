class Solution{
    public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid){
		int count = 0;

		int row = grid.size();
		int col = grid[0].size();

		int max_in_row[50] = {};
		int max_in_col[50] = {};

		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				max_in_row[i] = max(max_in_row[i],grid[i][j]);
                max_in_col[j] = max(max_in_col[j],grid[i][j]);
			}
		}

        for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				count += min(max_in_row[i]-grid[i][j],max_in_col[j]-grid[i][j]);
			}
		}
	
	return count;
	}
};