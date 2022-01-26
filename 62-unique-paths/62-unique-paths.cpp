class Solution {
public:
    int helper(int m,int n, vector<vector<int>> &dp){
        if(m==1 || n==1){
            return 1;
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        dp[m-1][n] = helper(m-1, n, dp);
        dp[m][n-1] = helper(m, n-1, dp);
        return dp[m-1][n]+dp[m][n-1];
    }
    int uniquePaths(int m, int n) {
        int mx=max(m,n);
        vector<vector<int>> dp(mx+1, vector<int>(mx+1,-1));
        return helper(m, n, dp);
    }
};