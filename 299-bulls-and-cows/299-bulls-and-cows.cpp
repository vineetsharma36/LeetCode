class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        unordered_map<char,int> mp1,mp2;
        for(auto& x:secret){
            mp1[x]++;
        }
        for(auto& x:guess){
            mp2[x]++;
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                x++;
                mp1[secret[i]]--;
                mp2[secret[i]]--;
            }
        }
        for(auto x: mp1){
            if(mp2.find(x.first)!=mp2.end())
            {
                y+=min(x.second, mp2[x.first]);
            }
        }
        string res=to_string(x)+'A'+to_string(y)+'B';
        return res;
    }
};