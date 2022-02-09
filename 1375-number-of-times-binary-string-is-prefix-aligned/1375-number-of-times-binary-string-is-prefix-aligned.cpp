class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res=0;
        priority_queue<int> one;
        priority_queue<int, vector<int>, greater<int>> zero;
        vector<int> status(flips.size(),0);
        for(int i=0;i<flips.size();i++){
            zero.push(i);
        }
        for(int i=0;i<flips.size();i++){
            one.push(flips[i]-1);
            status[flips[i]-1]=1;
            while(!zero.empty() && status[zero.top()]==1)
                zero.pop();
            if(!zero.empty() && one.top()<zero.top())
                res++;
            else if(!zero.empty() && one.top()>zero.top())
                continue;
            else if(zero.empty() || zero.top()>flips[i]-1)
                res++;
        }
        return res;
    }
};