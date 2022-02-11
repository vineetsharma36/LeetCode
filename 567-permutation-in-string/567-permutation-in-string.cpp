class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        vector<int> freq1(26,0), freq2(26,0);
        for(auto& x:s1)
            freq1[x-'a']++;
        for(int i=0;i<s1.length();i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)
            return true;
        for(int i=s1.length();i<s2.length();i++){
            freq2[s2[i-s1.length()]-'a']--;
            freq2[s2[i]-'a']++;
            if(freq1==freq2)
                return true;
        }
        return false;
    }
};