class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1=max(0, i-k);
                int r2=min(i+k, m-1);
                for(int r=r1;r<=r2;r++){
                    int c1=max(0, j-k);
                    int c2=min(j+k, n-1);
                    for(int c=c1;c<=c2;c++){
                        res[i][j]+=mat[r][c];
                    }
                }
            }
        }
        return res;
    }
};