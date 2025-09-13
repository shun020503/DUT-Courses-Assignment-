#include <iostream>
using namespace std;
class Temperature
{
    private:
    int temp;
    public:
    Temperature (int tmp)
    {
        temp = tmp;
    }
    bool isEthylFreezing()
    {
        if (temp<=-173) return true; else return false;
    }
    bool isEthylBoiling()
    {
        if (temp>=172) return true; else return false;
    }
    bool isOxygenFreezing()
    {
        if (temp<=-362) return true; else return false;
    }
    bool isOxygenBoiling()
    {
        if (temp>=-306) return true; else return false;
    }
    bool isWaterFreezing()
    {
        if (temp<=32) return true; else return false;
    }
    bool isWaterBoiling()
    {
        if (temp>=212) return true; else return false;
    }
};
int main()
{
    int tmp; int dem = 0;
    cout << "Enter the Temperature: "; cin >> tmp;
    Temperature t1(tmp);
    cout << "At that Temperature, the substances will freez is: " << endl;
    if (t1.isEthylFreezing()) { cout << "Ethyl Alcohol" << endl; dem +=1; }
    if (t1.isOxygenFreezing()) { cout << "Oxygen" << endl; dem +=1; }
    if (t1.isWaterFreezing()) { cout << "Water" << endl; dem+=1; }
    if (dem ==0) cout << "No substance will freez" << endl;
    dem = 0;
    cout << "At that Temperature, the substances will boil is: " << endl;
    if (t1.isEthylBoiling()) { cout << "Ethyl Alcohol" << endl; dem+=1; }
    if (t1.isOxygenBoiling()) { cout << "Oxygen" << endl; dem+=1; }
    if (t1.isWaterBoiling()) { cout << "Water" << endl; dem+=1; }
    if (dem ==0) cout << "No substance will boil" << endl;
    return 0;
}