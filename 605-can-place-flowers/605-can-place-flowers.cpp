class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        int res=0;
        if(s==1 && flowerbed[0]==0)
            return true;
        for(int i=0;i<s;i++)
        {
            if(i>0)
            {
                if(flowerbed[i-1]==1 || flowerbed[i]==1)
                    continue;
                else if(i+1<s && flowerbed[i+1]!=1)
                {
                    flowerbed[i]=1;
                    res++;
                }                
                else if(i+1==s)
                {
                    res++;
                }
            }
            else if(i==0)
            {
                if(flowerbed[i]==1)
                    continue;
                else if(i+1<s && flowerbed[i+1]!=1)
                {
                    flowerbed[i]=1;
                    res++;
                }
                else if(i+1==s && (i-1>=0 && flowerbed[i-1]!=1) )
                {
                    flowerbed[i]=1;
                    res++;
                }
            }
        }
        if(res>=n)
            return true;
        else 
            return false;
    }
};