class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum=0;
        int res=0;
        for(auto& x:nums)
            sum+=x;
        if(sum==goal)
            return 0;
        res=(abs(goal-sum))/limit+((abs(goal-sum))%limit!=0);
        return res;
    }
};