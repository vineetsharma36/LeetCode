class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> v(n+1,false);
        vector<int> freq(n+1,0);
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]]=true;
            freq[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(!v[i])
                if(freq[i]==n-1)
                    return i;
        }
        return -1;
    }
};