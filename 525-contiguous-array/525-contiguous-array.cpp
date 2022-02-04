class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        mp[0].push_back(-1);
        int c=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                c++;
            else
                c--;
            int n=mp[c].size();
            if(n<2){
                mp[c].push_back(i);
            }
            else{
                mp[c][1]=i;
            }
            if(n!=0){
                res=max(res, mp[c][1]-mp[c][0]);
            }
        }
        return res;
    }
};