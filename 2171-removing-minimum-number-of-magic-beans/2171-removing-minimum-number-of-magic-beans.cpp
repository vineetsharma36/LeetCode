class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long res=1e18, sum=0;
        int n=beans.size();
        for(int i=0;i<n;i++){
            sum+=beans[i];
        }
        for(int i=0;i<n;i++){
            res=min(res, sum-(long long)(n-i)*beans[i]);
        }
        return res;
    }
};