class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                string b=s.top();
                s.pop();
                string a=s.top();
                s.pop();
                int temp=0;
                if(tokens[i]=="+"){
                    temp=stoi(a)+stoi(b);
                }
                else if(tokens[i]=="-"){
                    temp=stoi(a)-stoi(b);
                }
                else if(tokens[i]=="/"){
                    temp=stoi(a)/stoi(b);
                }
                else{
                    temp=stoi(a)*stoi(b);
                }
                s.push(to_string(temp));
            }
            else{
                s.push(tokens[i]);
            }
        }
        return stoi(s.top());
    }
};