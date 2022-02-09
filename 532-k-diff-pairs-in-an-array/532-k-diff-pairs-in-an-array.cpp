class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto& x:nums)
            mp[x]++;
        for(auto& x:nums){
            if(k==0 && mp[x]>1 && s.find(x)==s.end()){
                res++;
                s.insert(x);
            }
            else if(k!=0 && s.find(x)==s.end() && mp[x+k]>=1){
                res++;
                s.insert(x);
            }
        }
        return res;
    }
};