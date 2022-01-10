class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int mx=0;
        for(auto& x:candies){
            mx=max(mx, x);
        }
        for(auto& x:candies){
            if(mx>(extraCandies+x)){
                res.push_back(false);
            }
            else{
                res.push_back(true);
            }
        }
        return res;
    }
};