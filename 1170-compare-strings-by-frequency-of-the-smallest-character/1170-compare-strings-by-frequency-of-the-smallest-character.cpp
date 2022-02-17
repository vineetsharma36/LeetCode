class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> f1, f2, res;
        for(int i=0;i<queries.size();i++){
            vector<int> freq(26,0);
            for(auto& x: queries[i]){
                freq[x-'a']++;
            }
            for(auto& x: freq){
                if(x>0){
                    f1.push_back(x);
                    break;
                }
            }
        }
        for(int i=0;i<words.size();i++){
            vector<int> freq(26,0);
            for(auto& x: words[i]){
                freq[x-'a']++;
            }
            for(auto& x: freq){
                if(x>0){
                    f2.push_back(x);
                    break;
                }
            }
        }
        sort(f2.begin(),f2.end(),greater<int>());
        for(auto& x: f1){
            int c=0;
            for(auto& z:f2){
                if(z>x)
                    c++;
                else
                    break;
            }
            res.push_back(c);
        }
        return res;
    }
};