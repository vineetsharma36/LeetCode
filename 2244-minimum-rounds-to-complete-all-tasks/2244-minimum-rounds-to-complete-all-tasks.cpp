class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int res=0;
        for(auto& x:tasks)
            mp[x]++;
        for(auto& x:mp){
            int temp=x.second;
            if(temp==1)
                return -1;
            else
            {
                res+=temp/3;
                temp%=3;
                if(temp==2 || temp==1){
                    res++;
                }
            }
        }
        return res;
    }
};