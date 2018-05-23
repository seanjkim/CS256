#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
using namespace std;

class Employee
{
    string name;
    int employeeNumber;
    string hireDate;
public:
    void setName(string n){name = n;}
    void setEmployeeNumber(int e)
    {
        if(e > 9999 || e < 0)
        {
            string invalidEmployeeNumber = "ERROR: Employee number must be within the range of 0-9999.\n";
            throw invalidEmployeeNumber;
        }
        employeeNumber = e;
    }
    void setHireDate(string h){hireDate = h;}
    
    string getName(){return name;}
    int getEmployeeNumber(){return employeeNumber;}
    string getHireDate(){return hireDate;}
    
    Employee()
    {
        name = "";
        employeeNumber = 0;
        hireDate = "";
    }
    Employee(string n, int e, string h)
    {
        name = n;
        employeeNumber = e;
        hireDate = h;
    }
};

class ProductionWorker : public Employee
{
    int shift;
    double hourlyPayRate;
public:
    void setShift(int s)
    {
        if(s > 2 || s < 0)
        {
            string InvalidShift = "ERROR: Shift must be 1 or 2.\n";
            throw InvalidShift;
        }
        shift = s;
    }
    void setHourlyPayRate(double h)
    {
        if(h < 0)
        {
            string InvalidPayRate = "ERROR: Pay rate must be positive or 0.";
            throw InvalidPayRate;
        }
        hourlyPayRate = h;
    }
    
    int getShift(){return shift;}
    int getHourlyPayRate(){return hourlyPayRate;}
    
    ProductionWorker()
    {
        shift = 0;
        hourlyPayRate = 0;
    }
    ProductionWorker(int s, double h, string n, int e, string hd) : Employee(n, e, hd)
    {
        shift = s;
        hourlyPayRate = h;
        setName(n);
        setEmployeeNumber(e);
        setHireDate(hd);
    }
};
int main()
{
    ProductionWorker employee1;
    
    string name;
    int shift;
    double hourlyPayRate;
    int employeeNumber;
    string hireDate;
    
    cout << "Please enter the name of the employee." << endl;
    cin >> name;
    employee1.setName(name);
    
    cout << "Please enter 1 for day shift of employee, or 2 for night shift of employee." << endl;
    cin >> shift;
    try
    {
        employee1.setShift(shift);
    }
    catch(string InvalidShift)
    {
        cout << InvalidShift;
    }
    
    cout << "Please enter the hourly pay rate of the employee." << endl;
    cin >> hourlyPayRate;
    try
    {
        employee1.setHourlyPayRate(hourlyPayRate);
    }
    catch(string InvalidPayRate)
    {
        cout << InvalidPayRate;
    }
    cout << "Please enter the employee number." << endl;
    cin >> employeeNumber;
    try
    {
        employee1.setEmployeeNumber(employeeNumber);
    }
    catch(string invalidEmployeeNumber)
    {
        cout << invalidEmployeeNumber;
    }
    
    cout << "Please enter the hire date of the employee." << endl;
    cin >> hireDate;
}
