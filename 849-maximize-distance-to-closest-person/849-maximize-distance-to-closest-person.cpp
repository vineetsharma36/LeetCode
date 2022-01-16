class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> v;
        int res=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1)
                v.push_back(i);
        }
        if(v.size()==1){
            int j=v[0]-0, k=seats.size()-1-v[0];
            res=max(j,k);
        }
        else{
            if(seats[0]==0){
                res=max(res, v[0]-0);
            }
            if(seats[n-1]==0){
                res=max(res, n-1-v[v.size()-1]);
            }
            for(int i=1;i<v.size();i++){
                int j=v[i-1],k=v[i];
                if(k-j==1)
                    continue;
                else{
                    int temp=j+(k-j)/2;
                    res=max(res, min(temp-j, k-temp));
                }
            }
        }
        return res;
    }
};