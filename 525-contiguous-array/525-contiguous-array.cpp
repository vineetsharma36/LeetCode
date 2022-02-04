class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int c=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                c++;
            else
                c--;
            if(mp.find(c)==mp.end())
                mp[c]=i;
            else
                res=max(res, i-mp[c]);
        }
        return res;
    }
};