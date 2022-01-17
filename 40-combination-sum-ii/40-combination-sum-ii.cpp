class Solution {
public:
    void helper(vector<int>& candidates, vector<vector<int>> &res, vector<int>& v, int i, int n, int target){
        if(target==0)
        {
            res.push_back(v);
            return;
        }
        for(int k=i;k<n;k++){
            if(k>i && candidates[k]==candidates[k-1])
                continue;
            if(candidates[k]<=target){
                v.push_back(candidates[k]);
                helper(candidates, res, v, k+1, n, target-candidates[k]);
                v.pop_back();
            }
            else{
                break;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        int i=0,n=candidates.size();
        helper(candidates, res, v, i, n, target);
        return res;
    }
};