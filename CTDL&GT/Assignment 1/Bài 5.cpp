#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Month
{
    private:
    string month;
    int monthnumber;
    public:
    Month () { monthnumber = 0; month = ""; }
    Month (int n, string m) { monthnumber = n; month = m; }
    void setmonthnumber(int n) { monthnumber = n; }
    void setmonth(string m) { month = m; }
    string getmonth()
    {
        if (monthnumber == 1) month = "January";
        if (monthnumber == 2) month = "February";
        if (monthnumber == 3) month = "March";
        if (monthnumber == 4) month = "April";
        if (monthnumber == 5) month = "May";
        if (monthnumber == 6) month = "June";
        if (monthnumber == 6) month = "June";
        if (monthnumber == 7) month = "July";
        if (monthnumber == 8) month = "August";
        if (monthnumber == 9) month = "September";
        if (monthnumber == 10) month = "October";
        if (monthnumber == 11) month = "November";
        if (monthnumber == 12) month = "December";
        return month;
    }
    int getnumber()
    {
        if (month == "January") monthnumber = 1;
        if (month == "February") monthnumber = 2;
        if (month == "March") monthnumber = 3;
        if (month == "April") monthnumber = 4;
        if (month == "May") monthnumber = 5;
        if (month == "June") monthnumber = 6;
        if (month == "July") monthnumber = 7;
        if (month == "August") monthnumber = 8;
        if (month == "September") monthnumber = 9;
        if (month == "October") monthnumber = 10;
        if (month == "November") monthnumber = 11;
        if (month == "December") monthnumber = 12;
        return monthnumber;        
    }
    Month& operator++()
    {
        if (monthnumber == 12) monthnumber = 1; 
        else monthnumber++;
        getmonth();
        return *this;
        
    }
    Month& operator++(int)
    {
        Month m(monthnumber, month);
        ++monthnumber; getmonth();
        return m;
    }
    Month&operator--()
    {
        if (monthnumber == 1) monthnumber = 12;
        else monthnumber--;
        getmonth();
        return *this;
    }
    Month& operator--(int)
    {
        Month m(monthnumber, month);
        --monthnumber;
        return m;
    }
    friend istream& operator >> ( istream& in, Month&m )
    {
        int n; string mo;
        cout << "Enter your month: "; in >> mo;
        cout << "Enter your month's number: "; in >> n;
        m.setmonthnumber(n);
        m.setmonth(mo);
        return in;
    }
    friend ostream& operator << ( ostream& out, Month &m)
    {
        out << m.getmonth();
        return out;
    }
};
int main ()
{
    
    Month m1;
    cin >> m1;
    cout << (--m1);
    return 0;
}
