// CUHK_CSCI 1120 assignment 1

#include <iostream>
using namespace std;

int check_ten(int digi){
  if(digi >= 10) return((digi%10)+(digi/10));
  else return digi;
}

long dev(long long x, int i){
    long dev_x;
    for (int j = 0; j < i; j++) x = x/(10000);
    dev_x = x%10000;
    return dev_x;
}

int zero(long x){
  if(x >= 1000);
  else if(x >= 100) cout << '0';
  else if(x >= 10) cout << "00";
  else if(x >= 0 ) cout << "000";
  return x;
}

int main(int argc, char const *argv[]) {

  while(1){
    long long x,y = 0;
    int check_num = 0;
    cout << "Enter a 15-digit partial card num: ";
    cin >> x;
    if(x < 0) {
      cout << "Bye!" << endl;
      break;
    }
    y = x;
    for(int i = 0; i < 15; i++){
      if((i%2) == 0)
      check_num += check_ten((y%10)*2);
      if((i%2) != 0)
      check_num += (y%10);
      y = y/10;
    }
    check_num = check_num * 9;
    check_num = check_num % 10;
    //cout << "check_num:" << check_num << endl;
    x = x*10 + check_num;
    cout << "Full card num is: " << zero(dev(x,3)) << "-" << zero(dev(x,2)) <<"-"<<zero(dev(x,1)) << "-" << zero(dev(x,0)) << endl;
  }
  return 0;
}
