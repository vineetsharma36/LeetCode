class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg,res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        int i=0;
        while(i<nums.size()/2){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
            i++;
        }
        return res;
    }
};