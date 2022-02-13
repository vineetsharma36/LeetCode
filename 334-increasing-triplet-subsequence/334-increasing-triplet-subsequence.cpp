class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool f1=true, f2=false, f3=false;
        int a=nums[0], b=INT_MAX, c=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<a){
                a=nums[i];
                continue;
            }
            if(nums[i]>a){
                if(nums[i]<b){
                    b=nums[i];
                    f2=true;
                }
                else if(nums[i]>b && f2){
                    c=nums[i];
                    f3=true;
                }
            }
            if(f1 && f2 && f3)
                return true;
        }
        return false;
    }
};