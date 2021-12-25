class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                c++;
            else
                break;
        }
        if(c>=k)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(k>0)
                {
                    sum+=nums[i]*-1;
                    k--;
                }
                else
                {
                    sum+=nums[i];
                }
            }
        }
        else if(c==0)
        {
            for(int i=1;i<nums.size();i++)
            {
                sum+=nums[i];
            }
            if(k&1)
                sum+=nums[0]*-1;
            else
                sum+=nums[0];
        }
        else
        {
            int mn=INT_MAX;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<0)
                {
                    sum+=nums[i]*-1;
                    mn=min(mn,nums[i]*-1);
                    k--;
                }
                else
                {
                    sum+=nums[i];
                    mn=min(mn,nums[i]);
                }
            }
            if(k&1)
            {
                sum-=mn*2;
            }
        }
        return sum;
    }
};