class Solution {
public:
    string letters(char c)
    {
        if(c=='2')
            return "abc";
        else if(c=='3')
            return "def";
        else if(c=='4')
            return "ghi";
        else if(c=='5')
            return "jkl";
        else if(c=='6')
            return "mno";
        else if(c=='7')
            return "pqrs";
        else if(c=='8')
            return "tuv";
        else
            return "wxyz";
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for(auto& x:digits)
        {
            vector<string> temp;
            string s=letters(x);
            if(res.size()==0)
            {
                for(auto& z:s)
                {
                    string p;
                    p=p+z;
                    res.push_back(p);
                }
                continue;
            }
            else
            {
                for(auto& z: res)
                {
                    for(auto& y:s)
                    {
                        string t=z+y;
                        temp.push_back(t);
                    }
                }
            }
            res=temp;
        }
        return res;
    }
};