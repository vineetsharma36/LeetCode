class Solution {
public:
    int findComplement(int num) {
        int r=log2(num);
        int temp=pow(2,r+1)-1;
        return temp^num;
    }
};