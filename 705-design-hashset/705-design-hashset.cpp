static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    vector<bool> presence;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(key>=presence.size())
        {
            presence.resize(key+1,false);
        }
        presence[key]=true;
    }
    
    void remove(int key) {
        if(key>=presence.size())
            return;
        if(!presence[key])
            return;
        presence[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(key>=presence.size())
            return false;
        if(!presence[key])
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */