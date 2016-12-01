#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;

Staff::Staff(string sid){
  int i = 0;
  while(sid[i] != '\0'){
    if((sid[i] > '9') || (sid[i] < '0')) sid.erase(i,1);
    else i++;
    //cout << sid << '\n' << i << '\n';
  }
  while(sid.length() < 8) sid = '0' + sid;
  while(sid.length() > 8) sid = sid.erase(0,1);
  id = sid;
  for(int i = 0; i < 12; i++){
    salary[i] = 0.0;
  }
  return;
}

string Staff::getID() const{
  return id;
}

double Staff::getSalary(int m)const{
  return salary[m - 1];
}

void Staff::setSalary(int m,double wage){
  if((m < 1)&&(m > 12)) return;
  if(wage <= 0) salary[m - 1] = 0;
  else salary[m-1] =  wage;
  return;
}

double Staff::annualIncome()const{
  double income = 0;
  for(int i = 0; i < 12;i++){
    income = income + salary[i];
  }
  return income;
}

bool Staff::transportSubsidy()const{
  if (annualIncome() < 125000.0) return true;
  else return false;
}
