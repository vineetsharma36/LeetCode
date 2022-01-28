class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto& x:nums)
            mp[x]++;
        for(auto& x:nums){
            if(mp[x]==1 && mp[x-1]==0 && mp[x+1]==0)
                res.push_back(x);
        }
        return res;
    }
};