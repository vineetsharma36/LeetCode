class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board){
        if(i<0 || j<0 || i>m-1 || j>n-1 || board[i][j]!='X')
            return;
        board[i][j]='.';
        dfs(i+1, j, m, n, board);
        dfs(i-1, j, m, n, board);
        dfs(i, j+1, m, n, board);
        dfs(i, j-1, m, n, board);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size(), res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(i, j, m, n, board);
                    res++;
                }
            }
        }
        return res;
    }
};