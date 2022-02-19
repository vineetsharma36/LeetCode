class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==0){
            vector<long long> res;
            long long i=2;
            for(;finalSum>=i;i+=2){
                if(finalSum>=2*i+2)
                    finalSum-=i;
                else{
                    i=finalSum;
                    finalSum=0;
                }
                res.push_back(i);
            }
            return res;
        }
        return {};
    }
};