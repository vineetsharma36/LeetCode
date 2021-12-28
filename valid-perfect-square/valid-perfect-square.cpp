#define ll long long int
class Solution {
public:
    bool isPerfectSquare(ll num) {
        for(ll i=1;i*i<=num;i++)
        {
            if(i*i==num)
                return true;
        }            
        return false;
    }
};