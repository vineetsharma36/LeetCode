class Solution {
public:
    //set<vector<int>> s;
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int>& v, int i, int n){
        if(i==n){
            /*if(s.find(v)==s.end()){
                s.insert(v);
                res.push_back(v);
            }*/
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(nums, res, v, i+1, n);
        v.pop_back();
        helper(nums, res, v, i+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, n=nums.size();
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, res, v, i, n);
        return res;
    }
};