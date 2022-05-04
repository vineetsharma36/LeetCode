class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int, int> mp;
        for(auto& x: nums){
            mp[x]++;
        }
        for(auto& x: nums){
            if(mp[x]<1 || mp[k-x]<1)
                continue;
            if(k-x==x){
                if(mp[x]>=2){
                    mp[x]-=2;
                    res++;
                }
            }
            else
            {
                mp[x]--;
                mp[k-x]--;
                res++;
            }
        }
        return res;
    }
};