//CUHK CSCI1120 assignment 3
#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 13;

bool check_win(char board[][N],int N,char player){
  for(int y = 0; y < N ; y++){
    for(int x = 0; x < N ; x++){
        if((board[y][x] == player)&&(board[y-1][x] == player)&&(board[y-2][x] == player)&&(board[y-3][x] == player)&&(board[y-4][x] == player))
            return true;
          if((board[y][x] == player)&&(board[y+1][x] == player)&&(board[y+2][x] == player)&&(board[y+3][x] == player)&&(board[y+4][x] == player))
            return true;
          if((board[y][x] == player)&&(board[y-1][x-1] == player)&&(board[y-2][x-2] == player)&&(board[y-3][x-3] == player)&&(board[y-4][x-4] == player))
            return true;
          if((board[y][x] == player)&&(board[y+1][x+1] == player)&&(board[y+2][x+2] == player)&&(board[y+3][x+3] == player)&&(board[y+4][x+4] == player))
            return true;
          if((board[y][x] == player)&&(board[y][x-1] == player)&&(board[y][x-2] == player)&&(board[y][x-3] == player)&&(board[y][x-4] == player))
            return true;
          if((board[y][x] == player)&&(board[y][x+1] == player)&&(board[y][x+2] == player)&&(board[y][x+3] == player)&&(board[y][x+4] == player))
            return true;
          if((board[y][x] == player)&&(board[y-1][x+1] == player)&&(board[y-2][x+2] == player)&&(board[y-3][x+3] == player)&&(board[y-4][x+4] == player))
            return true;
          if((board[y][x] == player)&&(board[y+1][x-1] == player)&&(board[y+2][x-2] == player)&&(board[y+3][x-3] == player)&&(board[y+4][x-4] == player))
            return true;
          }
        }
        return false;
}

void update(char board[][N],int N , char x , int y, char player){
  board[y][x] = player;
  return;
}

bool check_valid(char board[][N],int N, char x , int y){
  if(board[y][x] != '.') return false;
  else return true;
}

void display(char board[][N],int x){
  cout << "   A B C D E F G H I J K L M" << endl;
  for(int i = 0; i < N ; i++){
    if(i < 10) cout << ' ' ;
    cout << i;
    for(int j = 0; j < N; j++){
      cout << ' ' << board[i][j];
    }
    cout << endl;
  }
  return;
}

void set_game(char board[][N],int x) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = '.';
    }
  }
  return;
}


int main() {
  int draw = 0;
  char x;
  int y;
  char player = 'X';
  char board[N][N];
  set_game(board,N);

  while(1){

    display(board,N);
    cout << "Player " << player << ", make a move: ";
    cin >> x >> y;
    x = (int)x - 'A';
    // ***********waiting for valid input**************
    while(1){
      if(check_valid(board,N,x,y) == false){
        cout << "Invalid input. Try again!" << endl;
        cout << "Player " << player << ", make a move: ";
        cin >> x >> y;
        x = (int)x - 'A';
        continue;
      }else {
        update(board,N,x,y,player);
        draw++;
        break;
      }
    }
    //***************updated*****************

    if(check_win(board,N,player) == true){
      display(board,N);
      cout << "Player "<< player<<" wins!" << endl;
      break;
    }else if(draw >= N*N) {
      cout << "Draw game!" << endl;
      break;
    }
    if(player == 'X') player = 'O';
    else player = 'X';
  }
  return 0;
}
