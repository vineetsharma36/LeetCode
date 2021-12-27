class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<satisfaction.size();i++)
        {
            int s=0,c=1;
            for(int j=i;j<satisfaction.size();j++)
            {
                s+=(satisfaction[j]*c);
                c++;
            }
            res=max(res,s);
        }
        return res;
    }
};