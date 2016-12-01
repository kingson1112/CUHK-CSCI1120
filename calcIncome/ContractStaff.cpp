#include <string>
#include "Staff.h"
#include "ContractStaff.h"
using namespace std;

ContractStaff::ContractStaff(string sid, double gr):Staff(sid){
  gratuityRate = gr;
  return;
}

double ContractStaff::getGratuityRate() const{
  return gratuityRate;
}

void ContractStaff::setGratuityRate(double gr){
  if(gr < 0) gr = 0.0;
  gratuityRate = gr;
  return;
}

double ContractStaff::annualIncome() const{
  double income = 0;
  for(int i = 0; i < 12;i++){
    income = income + getSalary(i+1);
  }
  return income*(1+gratuityRate);
}

bool ContractStaff::transportSubsidy() const{
  if (annualIncome() < 130000.0) return true;
  else return false;
}
