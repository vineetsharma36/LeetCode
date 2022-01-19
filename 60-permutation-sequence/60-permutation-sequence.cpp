class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> v;
        for(int i=1;i<n;i++){
            fact*=i;
            v.push_back(i);
        }
        v.push_back(n);
        k--;
        string res;
        while(true){
            res=res+to_string(v[k/fact]);
            v.erase(v.begin()+k/fact);
            if(v.size()==0)
                break;
            k=k%fact;
            fact=fact/v.size();
        }
        return res;
    }
};