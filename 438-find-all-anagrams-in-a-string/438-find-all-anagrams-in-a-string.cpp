class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
            return {};
        vector<int> res;
        vector<int> sv(26,0), pv(26,0);
        for(int i=0;i<p.length();i++){
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        if(sv==pv)
            res.push_back(0);
        for(int i=p.length();i<s.length();i++){
            sv[s[i-p.length()]-'a']--;
            sv[s[i]-'a']++;
            if(sv==pv)
                res.push_back(i-p.length()+1);
        }
        return res;
    }
};