class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res=0, temp=0;
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-1 && temp%2==0 && nums[i]==nums[i+1])
            {
                temp--;
                res++;
            }
            temp++;
        }
        if(temp%2==0)
            return res;
        return res+1;
    }
};