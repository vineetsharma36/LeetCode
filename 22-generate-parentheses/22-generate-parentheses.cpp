class Solution {
public:
    void helper(int o, int c, string s, vector<string> &res){
        if(c==0){
            res.push_back(s);
            return;
        }
        if(o>0){
            s.push_back('(');
            helper(o-1, c, s, res);
            s.pop_back();        
        }
        if(c>o){
            s.push_back(')');
            helper(o, c-1, s, res);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }
};