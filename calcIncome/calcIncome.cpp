//CSCI-1120
//CUHK 2016 Fall

#include "Staff.h"
#include "ContractStaff.h"
#include "PartTimeStaff.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
  int n , data_num = 0;
  int i = 0; //use for vector;
  string x;
  string file_name;
  std::cout << "Enter file name: " ;
  getline(cin,file_name);
  fstream fin(file_name);

  if ( fin.fail() ) {
    cout << "Cannot open data file. Program exit!" << endl;
    exit( 1 );
  }

  fin >> x;
  //  std::cout << x << '\n';
  n = stoi(x);
  vector<Staff *> staffs(n); // Vector of superclass pointers
  while(!fin.eof()){
    fin >> x;
    if(strcmp(x.c_str(),"NS") == 0) {
      fin >> x;
      //std::cout << x << '\n';
      staffs[i] = new Staff(x);
      //  std::cout << i << "  "<<staffs[i]->getID() << '\n';

      for(int j = 1; j <= 12 ; j++){
        fin >> x;
        //  std::cout << x << '\n';
        staffs[i]->setSalary(j,stod(x));
      }
    }else if(x == "CS"){
      fin >> x;
      //  std::cout << x << '\n';
      staffs[i] = new ContractStaff(x);
      for(int j = 1; j <= 12 ; j++){
        fin >> x;
        //  std::cout << x << '\n';
        staffs[i]->setSalary(j,stod(x));
      }
      fin >> x;
      ((ContractStaff *)staffs[i])->setGratuityRate(stod(x));
    }else if(strcmp(x.c_str(),"PT") == 0){
      fin >> x;
      staffs[i] = new PartTimeStaff(x);
      for(int j = 1; j <= 12 ; j++){
        fin >> x;
        staffs[i]->setSalary(j,stod(x));
      }
      fin >> x;
      ((PartTimeStaff *)staffs[i])->setGratuityRate(stod(x));
    }
    // std::cout << i << "  "<<staffs[i]->getID() << '\n';
    if( i < n - 1) i++;
  }
  fin.close();

  std::cout << "Annual Income of "<< n <<" staff(s):" << '\n';
  for(int j = 0; j < n ; j++){
    std::cout << staffs[j]->getID() <<' ';
    std::cout <<std::fixed << setprecision(2) << staffs[j]->annualIncome() << ' ';
    if(staffs[j]->transportSubsidy() == true){
      std::cout << "Eligible" << '\n';
    }else std::cout << "Ineligible" << '\n';
  }
  for(int j = 0; j < n; j ++) delete staffs[j];
  //std::cout << staffs[0]->annualIncome() << '\n';
  return 0;
}
