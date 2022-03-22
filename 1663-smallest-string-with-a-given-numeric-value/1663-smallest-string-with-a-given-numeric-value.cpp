class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i=0;i<n;i++){
            res.push_back('a');
            k--;
        }
        int t=1;
        while(k>0){
            if(k>=25){
                res[n-t]+=25;
                k-=25;
            }
            else{
                res[n-t]+=k;
                k=0;
            }
            t++;
        }
        return res;
    }
};