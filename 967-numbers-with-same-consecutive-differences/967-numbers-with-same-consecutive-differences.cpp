class Solution {
public:
    void helper(int n, int k, vector<int> &res, int cur, int cursize){
        if(cursize == n){
            res.push_back(cur);
            return;
        }
        for(int i=0; i<10; i++){
            if(abs(cur%10 - i) == k){
                cur = cur*10+i;
                cursize++;
                helper(n, k, res, cur, cursize);
                cur/=10;
                cursize--;
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i=1; i<10; i++){
            helper(n, k, res, i, 1);
        }
        return res;
    }
};