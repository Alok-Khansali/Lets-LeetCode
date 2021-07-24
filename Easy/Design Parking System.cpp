class ParkingSystem {
public:
    int a[4]={0,0,0,0};
    ParkingSystem(int big, int medium, int small) {
        a[1]=big,a[2]=medium,a[3]=small;
    }
    bool addCar(int cartype) 
    {
         if(a[cartype]>0)
         {
             a[cartype]--;
            return(true);
         }
        return(false);
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
