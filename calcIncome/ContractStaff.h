#ifndef CONTRACTSTAFF_H
#define CONTRACTSTAFF_H

#include <string>
#include "Staff.h"
using namespace std;

class ContractStaff : public Staff {
public:
    ContractStaff(string sid = "00000000", double gr = 0.0);
    double getGratuityRate() const;
    void setGratuityRate(double gr);
    virtual double annualIncome() const;
    virtual bool transportSubsidy() const;
private:
    double gratuityRate;
};
#endif // STAFF_H
