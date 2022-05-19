class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0;
        for(int i=0; i<=31; i++){
            int c=0;
            for(auto& x:candidates)
                if((x>>i)&1)
                    c++;
            res=max(res, c);
        }
        return res;
    }
};