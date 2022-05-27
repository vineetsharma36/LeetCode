class Solution {
public:
    int numberOfSteps(int num) {
        if(!num)
            return 0;
        
        int res=0;
        
        while(num>1){
            if(num&1)
                res+=2;
            else
                res++;
            num=num>>1;
        }
        return res+1;
    }
};