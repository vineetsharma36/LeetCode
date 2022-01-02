class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1==version2)
            return 0;
        vector<int> v1,v2;
        string s;
        for(auto& x:version1){
            if(x=='.'){
                int z=0;
                for(int i=0;i<s.length();i++){
                    z=z*10+(s[i]-'0');
                }                
                v1.push_back(z);
                s="";
            }
            else{
                s+=x;
            }
        }
        int z=0;
        for(int i=0;i<s.length();i++){
            z=z*10+(s[i]-'0');
        }
        v1.push_back(z);
        s="";
        for(auto& x:version2){
            if(x=='.'){
                int z=0;
                for(int i=0;i<s.length();i++){
                    z=z*10+(s[i]-'0');
                }                
                v2.push_back(z);
                s="";
            }
            else{
                s+=x;
            }
        }
        z=0;
        for(int i=0;i<s.length();i++){
            z=z*10+(s[i]-'0');
        }
        v2.push_back(z);
        s="";
        
        int n=v1.size()>v2.size()?v2.size():v1.size();
        for(int i=0;i<n;i++){
            int s1=v1[i], s2=v2[i];
            if(s1==s2){
                continue;
            }
            else if(s1>s2){
                return 1;
            }
            else{
                return -1;
            }
        }
        for(int i=n;i<v1.size();i++){
            if(v1[i]>0)
                return 1;
        }
        for(int i=n;i<v2.size();i++){
            if(v2[i]>0)
                return -1;
        }
        return 0;
    }
};