class Solution {
public:
    void decreasing(long long &num){
        num*=-1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(), v.end(), greater<int>());
        for(auto& x: v){
            num=num*10+x;
        }
        num*=-1;
    }
    void increasing(long long &num){
        vector<int> v;
        int ind=-1;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(), v.end());
        if(v[0]==0)
        {
            for(int i=1;i<v.size();i++){
                if(v[i]!=0){
                    num=v[i];
                    ind=i;
                    break;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(i!=ind)
                num=num*10+v[i];
        }
    }
    long long smallestNumber(long long num) {
        if(num<0)
            decreasing(num);
        else if(num>0)
            increasing(num);
        return num;
    }
};