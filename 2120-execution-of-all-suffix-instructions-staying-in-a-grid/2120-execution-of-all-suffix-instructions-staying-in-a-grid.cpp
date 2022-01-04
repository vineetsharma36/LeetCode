class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for(int i=0;i<s.length();i++){
            int c=0;
            int a=startPos[0],b=startPos[1];
            for(int j=i;j<s.length();j++){
                if(s[j]=='U'){
                    a--;
                }
                else if(s[j]=='D'){
                    a++;
                }
                else if(s[j]=='R'){
                    b++;
                }
                else{
                    b--;
                }
                if(a<0 || b<0 || a>=n || b>=n)
                    break;
                c++;
            }
            res.push_back(c);
        }
        return res;
    }
};