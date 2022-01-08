class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> res(n,0);
        int t=pow(2,maximumBit)-1, x=nums[0];
        for(int i=1;i<n;i++)
            x=x^nums[i];
        for(int i=n-1;i>=0;i--){
            res[n-i-1]=x^t;
            x^=nums[i];
        }
        return res;
    }
};