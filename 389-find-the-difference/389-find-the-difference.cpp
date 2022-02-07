class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1=0;
        for(int i = 0;i<s.length();i++)
        {
            s1-=(s[i]-'a');
        }
        for(int i = 0;i<t.length();i++)
        {
            s1+=(t[i]-'a');
        }
        return (char)(s1+'a');
    }
};