class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0], y=queries[i][1], r=queries[i][2], c=0;
            double d;
            for(int j=0;j<points.size();j++){
                int a=points[j][0], b=points[j][1];
                d=sqrt((a-x)*(a-x)+(b-y)*(b-y));
                if(d<=(double)r)
                    c++;
            }
            res.push_back(c);
        }
        return res;
    }
};