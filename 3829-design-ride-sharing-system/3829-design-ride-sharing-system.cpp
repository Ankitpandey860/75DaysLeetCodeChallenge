class RideSharingSystem {
public:
    queue<int>driver,rider;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty()||driver.empty()) return {-1,-1};
        int rid=rider.front();
        int dri=driver.front();
        rider.pop();
        driver.pop();
        return {dri,rid};
    }
    
    void cancelRider(int riderId) {
        queue<int>temp;
        while(!rider.empty()){
            if(rider.front()==riderId){
                rider.pop();
                continue;
            }
            temp.push(rider.front());
            rider.pop();
        }
        while(!temp.empty()){
            rider.push(temp.front());
            temp.pop();
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */