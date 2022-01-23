class Solution {
public:
    void helper(int n, int low, int high, vector<int> &res){
        //cout<<n<<" ";
        if(n>high){
            return;
        }
        if(n>=low && n<=high){
            res.push_back(n);
        }
        if(n%10==9){
            return;
        }
        if(n==0){
            for(int i=1;i<=9;i++){
                n=n*10+(n%10+i);
                helper(n, low, high, res);
                n=n/10;
            }
        }
        else{
            n=n*10+(n%10+1);
            helper(n, low, high, res);
            n=n/10;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        helper(0, low, high, res);
        sort(res.begin(),res.end());
        return res;
    }
};