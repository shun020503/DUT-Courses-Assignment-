#include <iostream>
#include <iomanip>
using namespace std;
class employee
{
    private:
    string name;
    int idnumber;
    string department;
    string position;
    public:
    employee ()
    {
        name = ""; idnumber = 0; department = ""; position = "";
    }
    void setname (string n)
    {
        name = n;
    }
    void setidnumber (int id)
    {
        idnumber = id;
    }
    void setdepartment (string dep)
    {
        department = dep;
    }
    void setposition (string pos)
    {
        position = pos;
    }
    string getname()
    {
        return name;
    }
    int getidnumber()
    {
        return idnumber;
    }
    string getdepartment()
    {
        return department;
    }
    string getposition()
    {
    return position;
    }
};
int main()
{ 
    employee s1,s2,s3;
    s1.setname("Susan Meyers");
    s1.setidnumber(47889);
    s1.setdepartment("Accounting");
    s1.setposition("Vice President");
    s2.setname("Mark Jones");
    s2.setidnumber(39119);
    s2.setdepartment("It");
    s2.setposition("Programmer");
    s3.setname("Joy Rogers");
    s3.setidnumber(81774);
    s3.setdepartment("Manufacturing");
    s3.setposition("Engineer");
    cout << left << setw(20) << "Name" << left << setw(20) << "ID Number" << left << setw(20) << "Department" << "Position" << endl;
    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    cout << left << setw(20) << s1.getname() << left << setw(20) << s1.getidnumber() 
    << left << setw(20) << s1.getdepartment() << left << setw(20) << s1.getposition() << endl;  
    cout << left << setw(20) << s2.getname() << left << setw(20) << s2.getidnumber() 
    << left << setw(20) << s2.getdepartment() << left << setw(20) << s2.getposition() << endl;
    cout << left << setw(20) << s3.getname() << left << setw(20) << s3.getidnumber() 
    << left << setw(20) << s3.getdepartment() << left << setw(20) << s3.getposition() << endl;
    return 0;
}