class Solution {
public:
    int minOperations(int n) {
        int sum=0,res=0;
        for(int i=1;i<=2*n;i+=2){
            sum+=i;
        }
        sum/=n;
        for(int i=1;i<sum;i+=2){
            res+=sum-i;
        }
        return res;
    }
};