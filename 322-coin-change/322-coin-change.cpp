class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(),coins.end());
        for(int i=1; i<=amount; i++){
            dp[i]=INT_MAX;
            for(auto& x: coins){
                if(i-x<0)
                    break;
                if(dp[i-x]!=INT_MAX)
                    dp[i]=min(dp[i], dp[i-x]+1);
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};