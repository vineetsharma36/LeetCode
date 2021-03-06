class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (auto &price : prices) {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        
        return res;
    }
};