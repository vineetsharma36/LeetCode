#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        stack<char> l;
        int b1=0,b2=0,b3=0;
        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
        }
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            if(c==')')
            {
                b1--;
                if(!st.empty() && st.top()=='(')
                {
                    b1++;
                    st.pop();
                }
                else
                {
                    l.push(c);
                }
            }
            else if(c=='}')
            {
                b2--;
                if(!st.empty() && st.top()=='{')
                {
                    b2++;
                    st.pop();
                }
                else
                {
                    l.push(c);
                }
            }
            else if(c==']')
            {
                b3--;
                if(!st.empty() && st.top()=='[')
                {
                    b3++;
                    st.pop();
                }
                else
                {
                    l.push(c);
                }
            }
            else if(c=='(')
            {
                b1++;
                if(!l.empty() && l.top()==')')
                {
                    l.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(c=='{')
            {
                b2++;
                if(!l.empty() && l.top()=='}')
                {
                    l.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(c=='[')
            {
                b3++;
                if(!l.empty() && l.top()==']')
                {
                    l.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(b1!=0 || b2!=0 || b3!=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};