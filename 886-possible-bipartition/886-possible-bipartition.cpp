class Solution {
public:
    
    bool bfs(int node, vector<int> &color, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto& x:adj[n]){
                if(color[x]==-1){
                    color[x]=1-color[n];
                    q.push(x);
                }
                else if(color[x]==color[n])
                    return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(i, color, adj))
                    return false;
            }
        }
        return true;
    }
};