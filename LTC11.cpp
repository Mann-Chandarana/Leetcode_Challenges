/* 1603. Design Parking System */

#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 and this->big > 0)
        {
            this->big--;
            return true;
        }
        if (carType == 2 and this->medium > 0)
        {
            this->medium--;
            return true;
        }
        if (carType == 3 and this->small > 0)
        {
            this->small--;
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}