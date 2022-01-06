class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        unordered_map<int, vector<int>> mp; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto& x:mp){
            vector<int> v=x.second;
            sort(v.begin(),v.end());
            mp[x.first]=v;
        }
        vector<vector<int>> res(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]==0){
                    vector<int> v=mp[i-j];
                    int k=i,l=j,r=0;
                    while(k<m && l<n){
                        res[k++][l++]=v[r++];  
                    }                                      
                }
            }
        }
        return res;
    }
};