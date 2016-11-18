// name: Ng King Sang
// SID : 1155048424
// email : ngkingsang1112@gmail.com
// assignment 4 (CUHK - CSCI1120_2016_FALL)


#include <iostream>
#include <cstdlib>
#include "FifteenPuzzle.h"
using namespace std;


FifteenPuzzle::FifteenPuzzle(unsigned s){
  int z = 0;
  int i,j,p,q;
  steps = 0;
  for (int i = 0; i < 4; i++) {
    for(int j = 0;j < 4 ; j++) {
      board[i][j] = ++z;
    }
  }
  srand(s);
  for (int count = 0; count < 200; count++) {
    i = rand()% 4;
    j = rand()% 4;
    p = rand()% 4;
    q = rand()% 4;
    swap(board[i][j],board[p][q]);
  }

  for (int i = 0; i < 4; i++) {
    for(int j = 0;j < 4 ; j++) {
      if(board[i][j] == 16){
        r = i;
        c = j;
        //cout << r << "     " << c << endl;
        break;
      }
    }
  }

}

bool FifteenPuzzle::move(char dir){
  int i = 0;
  int j = 0;
  if(('a' <= dir)&&(dir <='z')) dir = dir - ('a' - 'A');
  if((dir != 'I')&&(dir != 'i')&&(dir != 'M')&&(dir != 'm')&&(dir != 'J')&&(dir != 'j')&&(dir != 'K')&&(dir != 'k')){
    return false;
  }else if((r == 3) && (dir =='M')) return false;
  else if((r == 0) && (dir =='I')) return false;
  else if((c == 0) && (dir =='J')) return false;
  else if((c == 3) && (dir =='K')) return false;
  else {
    if(dir == 'K') j = 1;
    else if(dir == 'I') i = -1;
    else if(dir == 'M') i = 1;
    else if(dir == 'J') j = -1;
    swap(board[r][c],board[r+i][c+j]);
    //cout << "swap" <<endl;
    steps ++;
    r = r + i;
    c = c + j;
    i = 0;
    j = 0;
    return true;
  }
}

void FifteenPuzzle::print()const{
  for (int i = 0; i < 4; i++) {
    for(int j = 0;j < 4 ; j++) {
      if(board[i][j] == 16) cout << "  .";
      else if(board[i][j] >= 10) cout << ' ' << board[i][j];
      else cout << "  " << board[i][j];
    }
    cout << endl;
  }
}

bool FifteenPuzzle::isSolved() const{
  int z = 0;
  int solved_board[4][4];
  for (int i = 0; i < 4; i++) {
    for(int j = 0;j < 4 ; j++) {
      solved_board[i][j] = ++z;
      if(board[i][j] != solved_board[i][j]) return false;
    }
  }
  return true;
}

int FifteenPuzzle::getSteps() const{
  return steps;
}
void swap(int &x, int &y){
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
  return;
}
