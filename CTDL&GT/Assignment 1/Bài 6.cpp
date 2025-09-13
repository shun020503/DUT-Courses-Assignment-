#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class PersonData
{
    private:
    string lastname;
    string firstname;
    string address;
    string city;
    string state;
    int zip;
    string phone;
    public:
    PersonData () { lastname = ""; firstname = ""; address = ""; city = ""; zip = 0; phone = ""; state = ""; }
    PersonData (string fn, string ln, string ct, string st, string ad, int zp, string ph)
    {
        lastname = ln; firstname = fn; address = ad; city = ct; zip = zp; phone = ph; state = st; 
    }
    string getfistname() { return firstname; }
    string getlastname() { return lastname; }
    string getaddress() { return address; }
    string getstate() { return state; }
    string getcity() { return city; }
    string getphone() { return phone; }
    int getzip() { return zip; }
};
class CustomerData : public PersonData
{
    private:
    int ctnumber;
    bool mailist;
    public: 
    CustomerData() : PersonData() { ctnumber = 0; mailist = 0; }
    CustomerData(int cn, bool ml, string fn, string ln, string ct, string st, string ad, int zp, string ph)
    : PersonData(fn,ln,ct,st,ad,zp,ph)
    {
        ctnumber = cn; mailist = ml;
    }
    int getctnumber() { return ctnumber; }
    bool getmailist() { return mailist; } 
    void print()
    {
        cout << left << setw(5) << "ID" << left << setw(15) << "First name" << left << setw(15) << "Last name"
        << left << setw(15) << "City" << left << setw(15) << "State" << left << setw(15) << "Address"
        << left << setw(15) << "Zip" << left << setw(15) << "Phone" << "Mailing list" << endl;
        cout << setfill('-') << setw(130) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << getctnumber() << left << setw(15) << getfistname() << left << setw(15) << getlastname()
        << left << setw(15) << getcity() << left << setw(15) << getstate() << left << setw(15) << getaddress()
        << left << setw(15) << getzip() << left << setw(15) << getphone() << (getmailist() ? "Yes" : "No") << endl;
    }
};
int main()
{
    string ln,fn,ad,ct,st,ph; int zp,cn; bool ml;
    cout << "Enter customer's first name: "; getline(cin,fn);
    cout << "Enter customer's last name: "; getline(cin,ln);
    cout << "Enter customer's city: "; getline(cin,ct);
    cout << "Enter customer's state: "; getline(cin,st);
    cout << "Enter customer's address: "; getline(cin,ad);
    cout << "Enter customer's zip: "; cin >> zp;
    cout << "Enter customer's phone: "; cin >> ph;
    cout << "Enter customer's number: "; cin >> cn;
    cout << "Enter customer's mailing list (1.True - 0.False): "; cin >> ml;
    CustomerData a(cn,ml,fn,ln,ct,st,ad,zp,ph);
    a.print();
    return 0;
}