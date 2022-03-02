class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        if(s.length()>t.length())
            return false;
        if(s.length()==t.length())
        {
            if(s!=t)
                return false;
            return true;
        }
        for(int i=0;i<t.length();i++)
        {
            if(j<s.length() && s[j]==t[i])
            {
                j++;
            }
            if(j==s.length())
            {
                return true;
            }
        }
        return false;
    }
};