class Solution {
public:
    void helper(int n, int k, int ind, vector<int> &v, vector<vector<int>> &res){
        if(v.size()==k){
            res.push_back(v);
            return;
        }
        for(int i=ind;i<=n;i++){
            v.push_back(i);
            helper(n, k, i+1, v, res);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        helper(n, k, 1, v, res);
        return res;
    }
};