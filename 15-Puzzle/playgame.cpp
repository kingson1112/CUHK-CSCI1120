
#include <iostream>
#include <cstdlib>
#include "FifteenPuzzle.h"
using namespace std;

int main(int argc, char const *argv[]) {
  unsigned s;
  char dir;
  std::cout << "Enter seed: ";
  std::cin >> s ;
  FifteenPuzzle fp(s); //step 1
  while(1){
    fp.print();
    std::cout << "Steps: " << fp.getSteps() <<  std::endl;

    while((dir != 'I')&&(dir != 'i')&&(dir != 'M')&&(dir != 'm')&&(dir != 'J')&&(dir != 'j')&&(dir != 'K')&&(dir != 'k')){
      std::cout << "Move [IMJK]: " ;
      std::cin >> dir;
      if((dir != 'I')&&(dir != 'i')&&(dir != 'M')&&(dir != 'm')&&(dir != 'J')&&(dir != 'j')&&(dir != 'K')&&(dir != 'k')) {
        cout << "Invalid. Try again!" << endl;
        continue;
      }
    }

    fp.move(dir);
    dir = (char)0;
    if(fp.isSolved() == true) {
      cout << "You finished in "<< fp.getSteps()<<" steps."<<endl;
      break;
    }
    else if(fp.getSteps() >= 200){
      cout << "You cannot finish in 200 steps." <<endl;
      break;
    }
  }

  return 0;
}
