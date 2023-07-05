class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        // vector<int> temp(nums.size(), 1);
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]>threshold)
        //         temp[i]=-1;
        //     if(nums[i]&1)
        //         temp[i]=1;
        //     else
        //         temp[i]=2;
        // }
        int res=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>threshold)
                continue;
            if(!(nums[i]&1))
            {
                int t=1;
                for(int j=i+1; j<nums.size(); j++){
                    if ((nums[j]%2 == nums[j-1]%2) || (nums[j]>threshold))
                        break;
                    t++;
                }
                res=max(res, t);
            }
        }
        return res;
    }
};