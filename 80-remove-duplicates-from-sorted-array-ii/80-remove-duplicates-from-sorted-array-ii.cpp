class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1,c=1, n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[k-1]==nums[i]){
                if(c==1){
                    nums[k++]=nums[i];
                    c++;
                }
                else{
                    continue;
                }
            }
            else{
                nums[k++]=nums[i];
                c=1;
            }
        }
        return k;
    }
};