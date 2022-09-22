static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int l,r;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                res.push_back(' ');
            }
            else
            {
                l=i;
                
                while(i!=n && s[i]!=' ')
                {
                    i++;
                }
                r=i;
                i--;
                string temp=s.substr(l,r-l);
                reverse(temp.begin(),temp.end());
                res+=temp;
            }
        }
        return res;
    }
};