#define ll long long int

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class FreqStack {
public:
    unordered_map<ll,ll> mp;
    priority_queue<pair<ll, pair<ll,ll>>> pq;
    int ind=0;
    FreqStack() {
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val], {ind,val}});
        ind++;
    }
    
    int pop() {
        
        ll res=pq.top().second.second;
        pq.pop();
        mp[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */