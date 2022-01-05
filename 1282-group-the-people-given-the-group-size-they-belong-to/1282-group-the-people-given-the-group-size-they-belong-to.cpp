class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> res;
        vector<vector<int>> z;
        for(int i=0;i<groupSizes.size();i++){
            res.push_back({groupSizes[i],i});
        }
        sort(res.begin(),res.end());
        vector<int> temp;
        for(int i=0;i<res.size();i++){
            temp.push_back(res[i].second);
            if(temp.size()==res[i].first){
                z.push_back(temp);
                temp={};
            }
        }
        return z;
    }
};