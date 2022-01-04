class Solution {
public:
    int count(string s){
        int c=0;
        for(auto& x:s)
            if(x=='1')
                c++;
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        int n=bank[0].size();
        vector<int> t;
        int res=0;
        for(int i=0;i<bank.size();i++){
            res=count(bank[i]);
            if(res>0)
                t.push_back(res);
        }
        res=0;
        for(int i=1;i<t.size();i++){
            res+=t[i-1]*t[i];
        }
        return res;
    }
};