class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // int n=0;
        // for(int i=0;i<matches.size();i++){
        //     n=max(n, max(matches[i][0], matches[i][1]));
        // }
        // vector<vector<int>> res(2);
        // vector<vector<int>> freq(n+1, vector<int>(2));
        // for(int i=0;i<matches.size();i++){
        //     freq[matches[i][0]][0]++;
        //     freq[matches[i][1]][1]++;
        // }
        // for(int i=1;i<=n;i++){
        //     if(freq[i][1]==0 && freq[i][0]>0){
        //         res[0].push_back(i);
        //     }
        //     else if(freq[i][1]==1){
        //         res[1].push_back(i);
        //     }
        // }
        // return res;
        vector<vector<int>> res(2);
        unordered_map<int, int> freq;
        for(int i=0;i<matches.size();i++){
            if(freq.find(matches[i][0])==freq.end())
                freq[matches[i][0]]=0;
            freq[matches[i][1]]++;
        }
        for(auto& x:freq){
            if(x.second==0)
                res[0].push_back(x.first);
            else if(x.second==1)
                res[1].push_back(x.first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};