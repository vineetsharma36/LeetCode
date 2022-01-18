class Solution {
public:    
    void helper(int col, int n, vector<string> &board, vector<vector<string>> &res, vector<int> &side, vector<int> &lower, vector<int> &upper){
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(side[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
                board[row][col]='Q';
                side[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                helper(col+1, n, board, res, side, lower, upper);
                board[row][col]='.';
                side[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        vector<int> side(n,0), lower(2*n-1, 0), upper(2*n-1, 0);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(0, n, board, res, side, lower, upper);
        return res;
    }
};