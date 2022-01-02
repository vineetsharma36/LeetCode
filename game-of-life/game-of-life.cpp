class Solution {
public:
    bool cell(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    
    void check(int i,int j, vector<vector<bool>> v, int m, int n, int &l, int &d){
        if(cell(i-1,j-1,m,n)){
            if(v[i-1][j-1])
                l++;
            else
                d++;
        }
        if(cell(i-1,j,m,n)){
            if(v[i-1][j])
                l++;
            else
                d++;
        }
        if(cell(i-1,j+1,m,n)){
            if(v[i-1][j+1])
                l++;
            else
                d++;
        }
        if(cell(i,j-1,m,n)){
            if(v[i][j-1])
                l++;
            else
                d++;
        }
        if(cell(i,j+1,m,n)){
            if(v[i][j+1])
                l++;
            else
                d++;
        }
        if(cell(i+1,j-1,m,n)){
            if(v[i+1][j-1])
                l++;
            else
                d++;
        }
        if(cell(i+1,j,m,n)){
            if(v[i+1][j])
                l++;
            else
                d++;
        }
        if(cell(i+1,j+1,m,n)){
            if(v[i+1][j+1])
                l++;
            else
                d++;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> v(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    v[i][j]=true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=0,d=0;
                check(i, j, v, m, n, l, d);
                if(v[i][j]){
                    if(l<2 || l>3)
                        board[i][j]=0;
                }
                else{
                    if(l==3)
                        board[i][j]=1;
                }
            }
        }
    }
};