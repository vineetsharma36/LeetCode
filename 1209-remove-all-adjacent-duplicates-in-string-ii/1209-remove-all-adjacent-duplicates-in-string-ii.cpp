class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string res;
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && s[i]==st.top().first){
                ++st.top().second;
                if(st.top().second==k){
                    st.pop();
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        while(!st.empty()){
            for(int j=0;j<st.top().second;j++)
                res.push_back(st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};