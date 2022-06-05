class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        for(int i=0; i<operations.size(); i++){
            mp[operations[i][1]]=mp[operations[i][0]];
            mp.erase(operations[i][0]);
        }
        for(auto x:mp){
            nums[x.second]=x.first;
        }
        return nums;
    }
};