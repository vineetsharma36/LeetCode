class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,-1), res;
        for(int i=s.length()-1;i>=0;i--){
            if(last[s[i]-'a']==-1)
                last[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++){
            vector<bool> vis(26, false);
            int ind=s[i]-'a';
            vis[ind]=true;
            for(int j=i+1;j<last[ind];j++){
                if(last[s[j]-'a']>last[ind]){
                    ind=s[j]-'a';
                }
            }
            res.push_back(last[ind]-i+1);
            i=last[ind];
        }
        return res;
    }
};