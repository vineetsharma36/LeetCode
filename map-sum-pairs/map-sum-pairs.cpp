class MapSum {
public:
    unordered_map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int s=0;
        for(auto& x:mp){
            string t=x.first;
            bool flag=true;
            for(int i=0;i<prefix.length();i++){
                if(prefix[i]!=t[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                s+=x.second;
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */