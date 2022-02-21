class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int occ=0,ele=0;
       for(int i=0;i<nums.size();i++)
       {
           if(occ==0)
           {
               ele=nums[i];
           }
           if(nums[i]==ele)
           {
               occ++;
           }
           else
           {
               occ--;
           }
       }
        return ele;
    }
};