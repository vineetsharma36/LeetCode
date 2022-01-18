class Solution {
public:
    bool safe(vector<string> &board, int row, int col, int n){
        int i=row, j=col;
        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q')
                return false;
        }
        row=i;
        col=j;
        while(col>=0){
            if(board[row][col--]=='Q')
                return false;
        }
        row=i;
        col=j;
        while(row<n && col>=0){
            if(board[row++][col--]=='Q')
                return false;
        }
        return true;
    }
    
    void helper(int col, int n, vector<string> &board, vector<vector<string>> &res){
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(board, row, col, n)){
                board[row][col]='Q';
                helper(col+1, n, board, res);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(0, n, board, res);
        return res;
    }
};