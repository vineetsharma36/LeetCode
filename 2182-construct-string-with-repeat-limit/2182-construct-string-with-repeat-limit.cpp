class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.begin(), s.end(), greater<char>());
        string res;
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int curf=0;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']>0){
                if(i>0 && s[i]!=s[i-1]){
                    curf=1;
                    freq[s[i]-'a']--;
                    res.push_back(s[i]);
                }
                if(curf==0 || (s[i]==s[i-1] && curf<repeatLimit)){
                    curf++;
                    freq[s[i]-'a']--;
                    res.push_back(s[i]);
                }
            }
            
            if(curf==repeatLimit){
                if(freq[s[i]-'a']>0){
                    for(int j=25;j>=0;j--){
                        if(s[i]-'a'!=j && freq[j]>0){
                            res.push_back('a'+j);
                            freq[j]--;
                            curf=0;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};