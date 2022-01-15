class ParkingSystem {
public:
    int b, cb=0, m, cm=0, s, cs=0;
    ParkingSystem(int big, int medium, int small) {
        b=big, m=medium, s=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(cb==b)
                return false;
            else{
                cb++;
                return true;
            }
        }
        else if(carType==2){
            if(cm==m)
                return false;
            else{
                cm++; 
                return true;
            }
        }
        else{
            if(cs==s)
                return false;
            else{
                cs++;
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */