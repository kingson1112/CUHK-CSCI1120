#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

class Staff {
public:
    Staff(string sid = "00000000");
    string getID() const;
    double getSalary(int m) const;
    void setSalary(int m, double wage);
    virtual double annualIncome() const;
    virtual bool transportSubsidy() const;
private:
    string id;
    double salary[12];
};
#endif // STAFF_H
