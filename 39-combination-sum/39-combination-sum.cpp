class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& candidates, vector<vector<int>> &res, vector<int>& v, int i, int n, int target){
        if(target==0)
        {
            if(s.find(v)==s.end()){
                s.insert(v);
                res.push_back(v);
            }            
            return;
        }
        if(i==n)
            return;
        for(int k=i;k<n;k++){
            if(candidates[k]<=target){
                v.push_back(candidates[k]);
                helper(candidates, res, v, k, n, target-candidates[k]);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        int i=0,n=candidates.size();
        helper(candidates, res, v, i, n, target);
        return res;
    }
};