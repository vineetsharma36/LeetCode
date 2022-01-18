class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& nums, int i, vector<vector<int>> &res){
        if(i==nums.size()){
            if(s.find(nums)==s.end()){
                s.insert(nums);
                res.push_back(nums);
            }
            return;
        }
        for(int k=i;k<nums.size();k++){
            if(k!=i && nums[k]==nums[k-1])
                continue;
            swap(nums[k],nums[i]);
            helper(nums, i+1, res);
            swap(nums[k],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
};