class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1=0,a2=0, b1=0, b2=0, i=0;
        bool flag=false, f1=false, f2=false, f3=false, f4=false;
        for(auto& x:num1){
            if(i!=0 && (x=='+' || x=='-')){
                cout<<i<<" ";
                flag=true;
                i++;
                continue;
            }
            else if(x=='-'){
                f1=true;
                i++;
                continue;
            }
            if(!flag){
                a1=a1*10+(x-'0');
            }
            else{
                if(x=='i')
                    continue;
                b1=b1*10+(x-'0');
                if(num1[i-1]=='-'){
                    f2=true;
                }
            }
            i++;
        }
        flag=false;
        i=0;
        for(auto& x:num2){
            if(i!=0 && (x=='+' || x=='-')){
                flag=true;
                i++;
                continue;
            }
            else if(x=='-'){
                f3=true;
                i++;
                continue;
            }
            if(!flag){
                a2=a2*10+(x-'0');
            }
            else{
                if(x=='i')
                    continue;
                b2=b2*10+(x-'0');
                if(num2[i-1]=='-'){
                    f4=true;
                }
            }
            i++;
        }
        if(f1)
            a1*=-1;
        if(f2)
            b1*=-1;
        if(f3)
            a2*=-1;
        if(f4)
            b2*=-1;
        return to_string(a1*a2-b1*b2)+"+"+to_string(a1*b2+a2*b1)+"i";
    }
};