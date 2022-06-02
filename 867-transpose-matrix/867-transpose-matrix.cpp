class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> res(n);
        int k=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i].push_back(matrix[j][k]);
            }
            k++;
        }
        return res;
    }
};