class Solution {
public:
    static bool sortbysec(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return (a[0] < b[0]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortbysec);
        int start=intervals[0][0], end=intervals[0][1], res=0;
        for(int i=1;i<intervals.size();i++){
            if(start<=intervals[i][0] && end>=intervals[i][1])
                continue;
            else{
                res++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        res++;
        return res;
    }
};