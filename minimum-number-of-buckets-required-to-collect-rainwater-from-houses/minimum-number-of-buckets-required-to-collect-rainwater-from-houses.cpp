class Solution {
public:
    int minimumBuckets(string street) {
        int n=street.length();
        if((n==1 && street[0]=='H') || (street[0]=='H' && street[1]=='H') || (street[n-1]=='H' && street[n-2]=='H')) 
           return -1;
        for(int i=1;i<n-1;i++)
        {
            if(street[i]=='H'){
                if(street[i-1]=='.' || street[i+1]=='.'){
                    
                }
                else
                    return -1;
            } 
        }
        int res=0;
        vector<bool> v(n,false);
        for(int i=0;i<n-1;i++)
        {
            if(v[i] || street[i]=='.')
                continue;
            if(i==0)
            {
                v[i]=true;
                if(street[i+2]=='H')
                {
                    v[i+2]=true;
                }
                res++;
            }
            else if(street[i-1]=='.' || street[i+1]=='.')
            {
                res++;
                v[i]=true;
                if(street[i+1]=='.' && i<n-2)
                {
                    if(street[i+2]=='H')
                    {
                        v[i+2]=true;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!v[i] && street[i]=='H')
            {
                res++;
            }
        }
        return res;
    }
};