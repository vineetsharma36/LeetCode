class Solution {
public:
    int charToInt(char c)
    {
        return c-64;
    }
    
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        long long int res=0;
        for(int i=0;i<n;i++)
        {
            res+=pow(26,n-1-i)*charToInt(columnTitle[i]);
        }
        return res;
    }
};