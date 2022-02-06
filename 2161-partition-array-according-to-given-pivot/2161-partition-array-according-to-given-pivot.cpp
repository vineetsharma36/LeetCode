class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res,mx;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)
                res.push_back(nums[i]);
            else if(nums[i]>pivot)
                mx.push_back(nums[i]);
            else
                c++;
        }
        while(c--)
            res.push_back(pivot);
        for(int i=0;i<mx.size();i++)
            res.push_back(mx[i]);
        return res;
    }
};