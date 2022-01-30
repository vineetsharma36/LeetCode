class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        vector<int>prefix(n,0), suffix(n,0);
        prefix[0]=(nums[0]==0);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(nums[i]==0);
        }
        suffix[n-1]=(nums[n-1]==1);
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+(nums[i]==1);
        }
        int mx=INT_MIN;
        for(int i=1;i<n;i++){
            if(prefix[i-1]+suffix[i]>mx){
                mx=prefix[i-1]+suffix[i];
                res.clear();
                res.push_back(i);
            }
            else if(prefix[i-1]+suffix[i]==mx){
                res.push_back(i);
            }
        }
        if(prefix[n-1]>mx){
            mx=prefix[n-1];
            res.clear();
            res.push_back(n);
        }
        else if(prefix[n-1]==mx){
            res.push_back(n);
        }
        if(suffix[0]>mx){
            mx=suffix[0];
            res.clear();
            res.push_back(0);
        }
        else if(suffix[0]==mx){
            res.push_back(0);
        }
        return res;
    }
};