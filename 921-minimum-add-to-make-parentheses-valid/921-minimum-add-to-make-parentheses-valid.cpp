class Solution {
public:
    int minAddToMakeValid(string s) {
        int l=0,r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                l++;
            else{
                if(l>0)
                    l--;
                else
                    r++;
            }
        }
        return l+r;
    }
};