class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    void helper(string s, int ind, vector<string> &v, vector<vector<string>> &res){
        if(ind==s.length())
        {
            res.push_back(v);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s, ind, i)){
                v.push_back(s.substr(ind, i-ind+1));
                helper(s, i+1, v, res);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        helper(s,0,v, res);
        return res;
    }
};