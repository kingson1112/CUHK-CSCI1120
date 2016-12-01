#ifndef PARTTIMESTAFF_H
#define PARTTIMESTAFF_H

#include <string>
#include "ContractStaff.h"
using namespace std;

class PartTimeStaff : public ContractStaff {
public:
    PartTimeStaff(string sid = "00000000", double gr = 0.0);
    virtual bool transportSubsidy() const;
};
#endif // PARTTIMESTAFF_H
