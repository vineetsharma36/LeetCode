class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        char dir='N';
        for(auto& i: instructions){
            if(i=='G'){
                if(dir=='N')
                    y++;
                else if(dir=='W'){
                    x--;
                }
                else if(dir=='S')
                    y--;
                else
                    x++;
            }
            else if(i=='L'){
                if(dir=='N'){
                    dir='W';
                }
                else if(dir=='W'){
                    dir='S';
                }
                else if(dir=='S'){
                    dir='E';
                }
                else{
                    dir='N';
                }
            }
            else{
                if(dir=='N'){
                    dir='E';
                }
                else if(dir=='E'){
                    dir='S';
                }
                else if(dir=='S'){
                    dir='W';
                }
                else{
                    dir='N';
                }
            }
        }
        if(dir!='N' || (x==0 && y==0))
            return true;
        return false;
    }
};