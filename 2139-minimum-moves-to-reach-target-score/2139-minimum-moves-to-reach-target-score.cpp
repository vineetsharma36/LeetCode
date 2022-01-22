class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res=0;
        while(target!=1 && maxDoubles>0){
            if(target%2==0)
            {
                target/=2;
                maxDoubles--;
                res++;
            }
            else{
                target--;
                res++;
            }
        }
        if(target!=1){
            res+=(target-1);
        }
        return res;
    }
};