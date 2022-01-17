class Solution {
public:

    void helper(vector<int>& candidates, vector<vector<int>> &res, vector<int>& v, int i, int n, int target){
        if(i==n){
            if(target==0)
            {
                res.push_back(v);
            }
            return;
        }
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            helper(candidates, res, v, i, n, target-candidates[i]);
            v.pop_back();
        }
        helper(candidates, res, v, i+1, n, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        int i=0,n=candidates.size();
        helper(candidates, res, v, i, n, target);
        return res;
    }
};