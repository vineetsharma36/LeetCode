class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v(26);
        set<string> st;
        vector<bool> isVisited(26,false);
        vector<string> words;
        int l=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                words.push_back(s.substr(l,i-l));
                l=i+1;
            }
        }
        words.push_back(s.substr(l));
        if(words.size()!=pattern.length())
            return false;
        for(int i=0;i<words.size();i++)
        {
            int j=(i%pattern.length());
            if(isVisited[pattern[j]-'a'])
            {
                if(v[pattern[j]-'a']!=words[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.find(words[i])!=st.end())
                {
                    return false;
                }
                isVisited[pattern[j]-'a']=true;
                v[pattern[j]-'a']=words[i];
                st.insert(words[i]);
            }
        }
        return true;
    }
};