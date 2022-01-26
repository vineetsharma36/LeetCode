class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
        if(m<1 || n<1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        if(n==1 && m==1)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        dp[m-1][n]=helper(obstacleGrid, m-1, n, dp);
        dp[m][n-1]=helper(obstacleGrid, m, n-1, dp);

        return dp[m][n]=dp[m-1][n]+dp[m][n-1];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return helper(obstacleGrid, m, n, dp);
    }
};