class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(101);
        for(int i=0;i<101;i++){
            v[i].resize(i+1,0.0);
        }
        v[0][0]=(double)(poured);
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<i+1;j++){
                double temp=(v[i][j]-1.0)/2.0;
                if(temp>0)
                {
                    v[i+1][j]+=temp;
                    v[i+1][j+1]+=temp;
                }
            }
            
        }
        if(v[query_row][query_glass]>=1)
            return 1.0;
        return v[query_row][query_glass];
    }
};