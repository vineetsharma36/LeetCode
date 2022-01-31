class CombinationIterator {
public:
    vector<string> v;
    int i=0;
    
    void helper(int ind, string characters, string temp, int combinationLength){
        if(temp.length()==combinationLength){
            v.push_back(temp);
            return;
        }
        if(ind==characters.length())
            return;
        for(int j=ind;j<characters.length();j++){
            temp.push_back(characters[j]);
            helper(j+1, characters, temp, combinationLength);
            temp.pop_back();
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        helper(0, characters, "", combinationLength);
    }
    
    string next() {
        return v[i++];
    }
    
    bool hasNext() {
        if(i<v.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */