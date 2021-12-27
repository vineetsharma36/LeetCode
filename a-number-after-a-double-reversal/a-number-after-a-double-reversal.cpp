class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp=num,rev1=0,rev2=0;
        while(temp)
        {
            rev1=rev1*10+(temp%10);
            temp/=10;
        }
        while(rev1)
        {
            rev2=rev2*10+(rev1%10);
            rev1/=10;
        }
        if(rev2==num)
            return true;
        return false;
    }
};