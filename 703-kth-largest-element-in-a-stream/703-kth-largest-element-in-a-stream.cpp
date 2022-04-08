static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto& x:nums){
            if(pq.size()>=k){
                if(x>pq.top())
                {
                    pq.pop();
                    pq.push(x);
                }
            }
            else
                pq.push(x);
        }
    }
    
    int add(int val) {
        if(pq.size()>=k){
            if(val>pq.top())
            {
                pq.pop();
                pq.push(val);
            }
        }
        else
            pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */