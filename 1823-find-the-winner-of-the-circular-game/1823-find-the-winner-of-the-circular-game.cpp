class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> v(n,true);
        int t=n-1,i=0,k1;
        while(t--){
            k1=k;
            while(true){
                if(v[i]){
                    k1--;
                    if(k1==0){
                        v[i]=false;
                        i++;
                        if(i>=n){
                            i%=n;
                        }
                        break;
                    }
                }
                i++;
                if(i>=n){
                    i%=n;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(v[i])
                return i+1;
        }
        return n;
    }
};