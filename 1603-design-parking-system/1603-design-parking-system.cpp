class ParkingSystem {
public:
    int one,two,three;
    ParkingSystem(int big, int medium, int small) {
        one=big;
        two=medium;
        three=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(one){
                one--;
                return true;
            }
            return false;
        }
        if(carType==2){
            if(two){
                two--;
                return true;
            }
            return false;
        }
        else{
            if(three){
                three--;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */