class Solution {
public:
    bool check(bitset<26> &a, bitset<26> &b){
        for(int i=0; i<26; i++){
            if(a[i] && b[i])
                return false;
        }
        return true;
    }
    
    
    int maxProduct(vector<string>& words) {
        int n=words.size(), mx=0;
        vector<bitset<26>> v(n);
        for(int i=0; i<n; i++){
            for(auto& x: words[i]){
                v[i][x-'a']=1;
            }
            for(int j=0; j<i; j++){
                if(check(v[i], v[j])){
                    int s=(words[i].length()*words[j].length());
                    mx=max(mx, s);
                }
            }
        }
        return mx;
        
    }
};