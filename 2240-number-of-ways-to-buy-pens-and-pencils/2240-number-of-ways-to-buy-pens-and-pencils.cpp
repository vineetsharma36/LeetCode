class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res=0;
        int x=total/cost1;
        for(int i=0; i<=x;i++){
            res+=(total-(i*cost1))/cost2+1;
        }
        return res;
    }
};