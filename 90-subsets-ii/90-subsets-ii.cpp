class Solution {
public:
    void helper(vector<int>& nums, int i, int n, vector<int> &v, vector<vector<int>> &res){
        if(i==n){
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(nums, i+1, n, v, res);
        v.pop_back();
        helper(nums, i+1, n, v, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<vector<int>> res, fin;
        vector<int> v;
        helper(nums, i, n, v, res);
        sort(res.begin(),res.end());
        set<vector<int>> s;
        v.clear();
        for(int i=0;i<res.size();i++){
            v=res[i];
            sort(v.begin(),v.end());
            if(s.find(v)==s.end()){
                fin.push_back(v);
                s.insert(v);
            }
        }
        return fin;
    }
};