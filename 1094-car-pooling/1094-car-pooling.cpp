class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size(),p=0;
        vector<vector<int>> from(n, vector<int>(2)), to(n, vector<int>(2));
        for(int i=0;i<n;i++){
            from[i][0]=trips[i][1];
            from[i][1]=trips[i][0];
            to[i][0]=trips[i][2];
            to[i][1]=trips[i][0];
        }
        sort(from.begin(),from.end());
        sort(to.begin(),to.end());
        int i=0,j=0;
        while(i<n && j<n){
            if(from[i][0]<to[j][0]){
                p+=from[i][1];
                if(p>capacity)
                    return false;
                i++;
            }
            else{
                p-=to[j][1];
                j++;
            }
        }
        return true;
    }
};