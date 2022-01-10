class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> res;
        vector<vector<int>> ans(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            ans[i]={abs(arr[i]-x), arr[i]};
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            res.push_back(ans[i][1]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};