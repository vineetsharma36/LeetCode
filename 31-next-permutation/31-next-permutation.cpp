class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int temp1=-1,res=INT_MAX,temp2=-1;
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                flag=true;
                break;
            }
        }
        if(n!=1 && flag)
        {
            for(int i=n-2;i>=0;i--)
            {
                if(nums[i]<nums[i+1])
                {
                    temp1=i;
                    break;
                }
            }
            for(int i=temp1+1;i<n;i++)
            {
                if(nums[i]>nums[temp1] && nums[i]<=res)
                {
                    res=nums[i];
                    temp2=i;
                }
            }
            swap(nums[temp1],nums[temp2]);
            int i=temp1+1,j=n-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        else
        {
            int i=0, j=n-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
    }
};