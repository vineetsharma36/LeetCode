// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void helper(int col, int n, vector<string> &board, vector<vector<string>> &v,
    vector<bool> &side, vector<bool> &upper, vector<bool> &lower){
        if(col==n){
            v.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(!side[i] && !lower[i+col] && !upper[n-1+col-i]){
                side[i]=true;
                lower[i+col]=true;
                upper[n-1+col-i]=true;
                board[col][i]='Q';
                helper(col+1, n, board, v, side, upper, lower);
                side[i]=false;
                lower[i+col]=false;
                upper[n-1+col-i]=false;
                board[col][i]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> v;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<bool> upper(2*n-1,false), lower(2*n-1,false), side(n,false);
        helper(0, n, board, v, side, upper, lower);
        vector<vector<int>> res;
        for(int i=0;i<v.size();i++){
            vector<int> temp;
            for(int j=0;j<v[i].size();j++){
                for(int k=0;k<v[i][j].length();k++){
                    if(v[i][j][k]=='Q')
                        temp.push_back(k+1);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends