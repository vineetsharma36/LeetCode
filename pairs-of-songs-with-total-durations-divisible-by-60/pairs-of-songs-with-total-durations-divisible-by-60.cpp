class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        unordered_map<int,int> mp;
        for(auto& x:time){
            x%=60;
        }
        for(auto& x:time){
            mp[x]++;
        }
        for(auto& x:mp){
            if(x.first==0){
                int c=x.second;
                c-=1;
                c=(c*(c+1))/2;
                res+=c;
            }
            int temp=60-x.first;
            if(mp.find(temp)==mp.end())
                continue;
            if(temp==x.first){
                int c=x.second;
                c-=1;
                c=(c*(c+1))/2;
                res+=c;
            }
            else if(temp>x.first){
                int c1=x.second;
                int c2=mp[temp];
                res+=c1*c2;
            }
        }
        return res;
    }
};