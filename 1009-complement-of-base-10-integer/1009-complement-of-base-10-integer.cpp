class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int i=1;
        while(i<n){
            i*=2;
        }
        if(i!=n)
            i-=1;
        else
            i*=2, i-=1;
        return n^i;
    }
};