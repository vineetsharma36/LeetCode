class Solution {
public:
    bool bfs(int node, vector<int> &res, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        res[node]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto& x: graph[n]){
                if(res[x]==-1){
                    q.push(x);
                    res[x]=1-res[n];
                }
                else{
                    if(res[x]==res[n])
                        return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            if(res[i]==-1){
                if(!bfs(i, res, graph))
                    return false;
            }
        }
        return true;
    }
};