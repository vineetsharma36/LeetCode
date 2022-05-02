class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd, even, res;
        for(auto& x:nums){
            if(x&1)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        for(auto& x:even)
            res.push_back(x);
        for(auto& x:odd)
            res.push_back(x);
        return res;
    }
};