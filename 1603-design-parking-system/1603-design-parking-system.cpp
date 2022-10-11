class ParkingSystem
{
    public:
        int sizes[3];

    ParkingSystem(int big, int medium, int small)
    {
        sizes[0] = big;
        sizes[1] = medium;
        sizes[2] = small;
    }

    bool addCar(int carType)
    {
        if (sizes[carType - 1] > 0)
        {
            sizes[carType - 1]--;
            return true;
        }
        else return false;
    }
};
/**
 *Your ParkingSystem object will be instantiated and called as such:
 *ParkingSystem* obj = new ParkingSystem(big, medium, small);
 *bool param_1 = obj->addCar(carType);
 */