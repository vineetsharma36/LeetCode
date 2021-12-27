class Solution {
public:
    string convertToTitle(int c) {
        string res="";
        int r;
        while(c>=26){
            r=c%26;
            c/=26;
            r--;
            char ch;
            if(r==-1){
                ch='Z';
                c--;
            }
            else
                ch='A'+r;
            res=ch+res;
        }
        if(c>0){
            res=(char)(c-1+'A')+res;
        }
        return res;
    }
};