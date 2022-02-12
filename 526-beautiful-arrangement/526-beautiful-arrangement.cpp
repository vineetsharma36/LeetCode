class Solution {
public:
    void perm(int ind, int n, vector<int> &v, int &res){
        if(ind==n){
            res++;
            return;
        }
        for(int i=ind;i<n;i++){
            if(v[i]%(ind+1)==0 || (ind+1)%v[i]==0){
                swap(v[ind], v[i]);
                perm(ind+1, n, v, res);
                swap(v[ind], v[i]);
            }
        }
    }
    
    int countArrangement(int n) {
        int res=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        perm(0, n, v, res);
        return res;
    }
};