class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int res=max(top-special[special.size()-1], special[0]-bottom);
        for(int i=1;i<special.size();i++){
            res=max(res, special[i]-special[i-1]-1);
        }
        return res;
    }
};