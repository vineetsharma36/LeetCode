class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=INT_MIN,l=1;
        for(auto& x: piles){
            m=max(m,x);
        }
        while(l<m){
            int mid=l+(m-l)/2;
            int hours=0;
            for(auto& x: piles){
                hours+=(x/mid)+((x%mid)!=0);
            }
            if(hours<=h){
                m=mid;
            }
            else{
                l=mid+1;
            }
        }
        return m;
    }
};