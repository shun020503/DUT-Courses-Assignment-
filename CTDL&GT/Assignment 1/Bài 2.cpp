#include <iostream>
using namespace std;
class Car
{
    private:
    int yearmodel;
    string make;
    int speed;
    public:
    Car (int ym, string m)
    {
        yearmodel = ym;
        make = m;
        speed = 0;
    }
    int getyearmodel()
    {
        return yearmodel;
    }
    string getmake()
    {
        return make;
    }
    int getspeed()
    {
        return speed;
    }
    void accelerate()
    {
        speed += 5;
    }
    void brake()
    {
        speed -=5;
    }
};
int main()
{
    int ym; string m;
    cout << "Enter car's year model: "; cin >> ym;
    cout << "Enter car's make: "; cin >> m;
    Car c1(ym,m);
    for (int i=1; i<=5; i++)
    {
        c1.accelerate();
        cout << "The current speed after acclerating " << i << " times is: " << c1.getspeed() << endl;
    }
    for (int i=1; i<=5; i++)
    {
        c1.brake();
        cout << "The current speed after braking " << i << " times is: " << c1.getspeed() << endl;
    }
    return 0;
}