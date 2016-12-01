#include <string>
#include "ContractStaff.h"
#include "PartTimeStaff.h"
#include "Staff.h"
using namespace std;

PartTimeStaff::PartTimeStaff(string sid, double gr):ContractStaff(sid,gr){
  return;
}
bool PartTimeStaff::transportSubsidy() const{
  double min_sal;
  for(int i = 1; i <= 12 ; i++){
    if(getSalary(i) < min_sal) min_sal = getSalary(i);
  }
  if(min_sal < 8300.0) return true;
  else return false;
}
