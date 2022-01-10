class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long int sum=0;
        for(auto& x: chalk){
            sum+=x;
        }
        if(k>=sum){
            k%=sum;
        }
        for(int i=0;i<chalk.size();i++){
            if(k<chalk[i])
                return i;
            k-=chalk[i];
        }
        return 0;
    }
};