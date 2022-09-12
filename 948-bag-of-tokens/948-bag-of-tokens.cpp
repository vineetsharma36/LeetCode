class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1, score=0, res=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                score++;
            }
            else if(score>=1){
                power+=tokens[j];
                j--;
                score--;
            }
            else{
                break;
            }
            res=max(res, score);
        }
        return res;
    }
};