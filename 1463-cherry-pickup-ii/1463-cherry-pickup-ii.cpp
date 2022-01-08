class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(70, vector<vector<int>>(70, vector<int>(70, -1)));
        return max(0, helper(grid, dp, 0, 0, m-1, n, m));
    }
    
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int r, int c1, int c2, int n, int m){
        if(r>=n || c1>=m || c2>=m || c1<0 || c2<0)  // So that we don't go over the edges of the grid
			return 0;
        
		/*
			if dp[r][c1][r2] is -1,  that means we haven't computed subanswer for that state. 
			otherwise we just return calculated subanswer. 
		*/
        if(dp[r][c1][c2] != -1) 
			return dp[r][c1][c2];
        
		// IMP: If both robots are on the same row and column, we consider value of that column only once
        int ans = (c1==c2) ? grid[r][c1] : grid[r][c1]+grid[r][c2];
        
		// Following are the possibilities to go to for both the robots:
		//    R1     |      R2
		// ----------------------
		//   c1      |     c2-1
		//   c1-1    |     c2
		//   c1      |     c2+1
		//   c1+1    |     c2
		//   c1+1    |     c2+1
		//   c1-1    |     c2-1
		//   c1+1    |     c2-1
		//   c1-1    |     c2+1
		
        int cherries = 0;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                int newC1 = c1 + i, newC2 = c2 + j;
                cherries = max(cherries, helper(grid, dp, r + 1, newC1, newC2, n, m));
            }
        
        dp[r][c1][c2] = ans + cherries;
        return dp[r][c1][c2];
    }
};