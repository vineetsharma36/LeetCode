class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0, r=0, res=0;
        for(auto& x: s){
            if(x=='(')
                l++;
            else
                r++;
            if(l==r){
                res=max(res, 2*l);
            }
            if(r>l){
                l=0;
                r=0;
            }
        }
        l=0;
        r=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r){
                res=max(res, 2*l);
            }
            if(l>r){
                l=0;
                r=0;
            }
        }
        return res;
    }
};