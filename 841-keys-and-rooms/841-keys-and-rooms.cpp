class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> v(n,false);
        stack<int> keys;
        keys.push(0);
        while(!keys.empty()){
            int k=keys.top();
            keys.pop();
            if(!v[k]){
                v[k]=true;
                for(int i=0;i<rooms[k].size();i++){
                    keys.push(rooms[k][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!v[i])
                return false;
        }
        return true;
    }
};