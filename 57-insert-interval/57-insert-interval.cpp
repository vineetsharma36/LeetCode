class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        int x=newInterval[0], y=newInterval[1],start,end;
        
        bool flag=false;
        if(y<intervals[0][0]){
            res.push_back({x,y});
            flag=true;
        }
        for(int i=0;i<intervals.size();i++){
            if(flag){
                res.push_back(intervals[i]);
            }
            else{
                if(x<intervals[i][0] && y<intervals[i][0])
                {
                    res.push_back(newInterval);
                    flag=true;
                    res.push_back(intervals[i]);
                }
                else if(x<=intervals[i][0])
                {
                    start=x;
                    if(y>=intervals[i][1]){
                        end=y;
                        i++;
                        for(;i<intervals.size();i++){
                            if(end>=intervals[i][0]){
                                if(intervals[i][1]>=end){
                                    end=intervals[i][1];
                                    break;
                                }
                                else{
                                    continue;
                                }
                            }
                            else{
                                i--;
                                break;
                            }
                        }
                        res.push_back({start,end});
                        flag=true;
                    }
                    else{
                        end=intervals[i][1];
                        res.push_back({start,end});
                        flag=true;
                    }
                }
                else if(x>intervals[i][0] && y<=intervals[i][1]){
                    start=intervals[i][0];
                    end=intervals[i][1];
                    res.push_back({start,end});
                    flag=true;
                }
                else if(x>intervals[i][0] && x<=intervals[i][1] && y>intervals[i][1]){
                    start=intervals[i][0];
                    end=y;
                    i++;
                    for(;i<intervals.size();i++){
                        if(end>=intervals[i][0]){
                            if(intervals[i][1]>=end){
                                end=intervals[i][1];
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        else{
                            i--;
                            break;
                        }
                    }
                    res.push_back({start,end});
                    flag=true;
                }
                else{
                    res.push_back(intervals[i]);
                }
            }
        }
        if(!flag){
            res.push_back({x,y});
        }
        return res;
    }
};