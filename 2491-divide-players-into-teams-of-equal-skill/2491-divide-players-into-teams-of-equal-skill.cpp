class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int tot_skill_per_team = skill[0]+skill[skill.size()-1];
        long long chemistry = (long long)skill[0]*skill[skill.size()-1];
        for(int i=1; i<skill.size()/2; i++){
            if(skill[i]+skill[skill.size()-i-1]==tot_skill_per_team)
            {
                chemistry += (long long)skill[i]*skill[skill.size()-i-1];
                continue;
            }
            return -1;
        }
        return chemistry;
    }
};