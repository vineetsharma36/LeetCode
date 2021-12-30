class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int t=k,r=0,l=1;
        while(t--){
            r=(r*10+1)%k;
            if(r==0){
                return l;
            }
            l++;
        }
        return -1;
    }
};