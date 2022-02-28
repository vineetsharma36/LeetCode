#define ll long long int

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> s;
        if(n==0)
            return s;
        if(n==1)
        {
            s.push_back(to_string(nums[0]));
            return s;
        }
        ll beg,en,prev=0;
        bool flag1=false,flag2;
        for(int i=0;i<n;i++)
        {
            if(!flag1)
            {
                beg=nums[i];
                prev=nums[i];
                flag1=true;
                flag2=false;
                if(i==n-1)
                {
                    string r=to_string(beg);
                    s.push_back(r);
                }
                continue;
            }
            else
            {
                if(nums[i]-prev==1)
                {
                    en=nums[i];
                    prev=nums[i];
                    flag2=true;
                    if(i==n-1)
                    {
                        string r=""+to_string(beg)+"->"+to_string(en);
                        s.push_back(r);
                    }
                }
                else
                {
                    if(flag2)
                    {
                        string r=""+to_string(beg)+"->"+to_string(en);
                        s.push_back(r);
                    }
                    else
                    {
                        string r=to_string(beg);
                        s.push_back(r);
                    }
                    flag1=false;
                    flag2=false;
                    i--;
                }
            }
        }
        return s;
    }
};