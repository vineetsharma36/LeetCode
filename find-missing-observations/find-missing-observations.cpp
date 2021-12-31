class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=mean*(n+m);
        for(auto& x:rolls)
            sum-=x;
        if(sum>n*6 || sum<n)
            return {};
        vector<int> res;
        int x=n;
        for(int i=0;i<n;i++){
            int temp=sum/x;
            res.push_back(temp);
            sum-=temp;
            x--;
        }
        return res;
    }
};