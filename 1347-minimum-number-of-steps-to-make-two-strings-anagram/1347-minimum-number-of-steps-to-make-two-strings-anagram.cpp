class Solution {
public:
    int minSteps(string s, string t) {
        int res=0;
        vector<int> freq(26,0);
        for(auto& x: s){
            freq[x-'a']++;
        }
        for(auto& x: t){
            freq[x-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                res+=freq[i];
        }
        return res;
    }
};