class Solution {
public:
    void helper(vector<int>& nums, int i, int n, vector<int> &v, vector<vector<int>> &res){
        res.push_back(v);
        for(int k=i;k<n;k++){
            if(i!=k && nums[k]==nums[k-1])
                continue;
            v.push_back(nums[k]);
            helper(nums, k+1, n, v, res);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, i, n, v, res);
        return res;
    }
};