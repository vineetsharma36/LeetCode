class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0,flip=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                ones++;
            else
                flip++;
            flip=(ones>flip)?flip:ones;
        }
        return flip;
    }
};