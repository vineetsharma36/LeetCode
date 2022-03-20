class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> freq(6,0);
        int res=-1;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=bottoms[i]){
                freq[bottoms[i]-1]++;
            }
            freq[tops[i]-1]++;
        }
        for(int i=0;i<6;i++){
            if(freq[i]==tops.size()){
                int temp1=0, temp2=0;
                for(auto& x: tops){
                    if(x!=i+1)
                        temp1++;
                }
                for(auto& x: bottoms){
                    if(x!=i+1)
                        temp2++;
                }
                if(res==-1){
                    res=min(temp1, temp2);
                }
                else{
                    res=min(res, min(temp1, temp2));
                }
            }
        }
        return res;
    }
};