class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res=0,c=0;
        for(auto& x:nums)
            s.insert(x);
        int temp;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                c=1;
                temp=nums[i]+1;
                while(s.find(temp)!=s.end()){
                    c++;
                    temp++;
                }
                res=max(c, res);
            }
        }
        return res;
    }
};