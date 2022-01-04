class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        vector<int> v1(10,0),v2(10,0);
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                x++;
            }
            else{
                v1[secret[i]-'0']++;
                v2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            y+=min(v1[i],v2[i]);
        }
        string res=to_string(x)+'A'+to_string(y)+'B';
        return res;
    }
};