// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m, vector<vector<bool>> &vis, vector<string> &res, string s, int i, int j, int n, vector<int> &di, vector<int> &dj){
        if(i==n-1 && j==n-1){
            res.push_back(s);
            return;
        }
        string x="DLRU";
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && nj>=0 && ni<n && nj<n && !vis[ni][nj] && m[ni][nj]==1){
                vis[i][j]=true;
                helper(m, vis, res, s+x[k], ni, nj, n, di, dj);
                vis[i][j]=false;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return res;
        string s;
        vector<int> di{1,0,0,-1}, dj{0,-1,1,0};
        helper(m, vis, res, s, 0, 0, n, di, dj);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends