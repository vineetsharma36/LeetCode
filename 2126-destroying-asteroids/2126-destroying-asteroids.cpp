#define ll long long int
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        ll m=mass;
        for(auto& x: asteroids){
            if(x>m)
                return false;
            if(m>=asteroids[asteroids.size()-1])
                return true;
            m+=x;
        }
        return true;
    }
};