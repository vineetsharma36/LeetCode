class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int res=0;
        while(true){
            a=pq.top();pq.pop();
            b=pq.top();pq.pop();
            if(b==0)
                break;
            a--;
            b--;
            res++;
            pq.push(a);
            pq.push(b);
        }
        return res;
    }
};