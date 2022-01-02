class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        set<int> s;
        s.insert(1);
        int i=0,j=0,k=0,res;        
        n--;
        while(n--){
            int x = *std::next(s.begin(), i);
            int y = *std::next(s.begin(), j);
            int z = *std::next(s.begin(), k);
            res=min(x*2,y*3);
            res=min(res,z*5);        
            if(res==x*2)
                i++;
            if(res==y*3)
                j++;
            if(res==z*5)
                k++;
            if(s.find(res)==s.end())
                s.insert(res);
            else
                n++;
        }
        return res;
    }
};