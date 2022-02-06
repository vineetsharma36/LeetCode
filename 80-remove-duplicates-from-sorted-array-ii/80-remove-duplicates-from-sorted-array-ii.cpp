class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second==1)
            {
                nums[k]=i.first;
                k++;
            }
            else if(i.second>=2)
            {
                nums[k]=i.first;
                k++;
                nums[k]=i.first;
                k++;
            }
        }
        return k;
    }
};