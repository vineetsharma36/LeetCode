class Solution {
public:
    bool detectCapitalUse(string word) {
        bool f1=false,f2=false,f3=false,f=true;
        int n=word.length();
        if(n==1 && word[0]>=65 && word[0]<=90)
            return true;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(word[i]>=65 && word[i]<=90)
                {
                    if(word[i+1]>=65 && word[i+1]<=90)
                    {
                        f1=true;
                        i++;
                    }
                    else
                    {
                        f3=true;
                        i++;
                    }                    
                }                    
                else 
                {
                    f2=true;
                }
            }
            if(f1)
            {
                if(!(word[i]>=65 && word[i]<=90))
                {
                    f=false;
                    break;
                }
            }
            else if(f2)
            {
                if(!(word[i]>=97 && word[i]<=122))
                {
                    f=false;
                    break;
                }
            }
            else if(f3)
            {
                if(!(word[i]>=97 && word[i]<=122))
                {
                    f=false;
                    break;
                }
            }
        }
        return f;
    }
};