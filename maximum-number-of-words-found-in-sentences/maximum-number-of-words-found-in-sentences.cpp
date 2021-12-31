class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=INT_MIN;
        for(int i=0;i<sentences.size();i++){
            string s=sentences[i];
            int c=0;
            for(auto& x:s){
                if(x==' ')
                    c++;
            }
            mx=max(mx,c+1);
        }
        return mx;
    }
};