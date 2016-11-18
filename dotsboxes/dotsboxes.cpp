// CUHK_CSCI 1120 assignment 2

#include <iostream>

using namespace std;

void add_score(long long &grid, int p){
  if(p == 1)
    grid = grid + 10;
  if(p == 2)
    grid = grid + 1;
}

int playerScore(long long grid, int p){
  int return_value = 0;
  if(p == 1){
    return_value = ( grid / 10) % 10;
    return return_value;
  }else if(p == 2){
    return_value = grid % 10;
    return return_value;
  }
  return 0;
}

bool isFilled(long long grid, int pos){
  //Returns true if position pos of grid is filled with a line; returns false otherwise.
  pos = 18 - pos;
  for (int i = 1; i <= pos; i++) {
    grid = grid / 10;
  }
  if(grid % 10 == 1) return true;
  else return false;
}

void displayGrid(long long grid){
    //This function prints grid to the screen using the format in Figure 1.
    cout << "   o";
    //***********************
    if(isFilled(grid,1) == true)
    cout << "--";
    else
    cout << "  ";
    //***********************
    cout <<  "o   " << std::endl;
    cout <<"   ";
    //************************
    if(isFilled(grid,2) == true)
    cout << "|";
    else
    cout << " ";
    //*************************
    cout << "  ";
    //*************************
    if(isFilled(grid,3) == true)
    cout << "|"<< endl;
    else
    cout << " " << endl;
    //*************************
    cout << "o";
    //***********************
    if(isFilled(grid,4) == true)
    cout << "--" << "o";
    else
    cout << "  "<<"o";
    //***********************
    //***********************
    if(isFilled(grid,5) == true)
    cout << "--" <<"o";
    else
    cout << "  "<<"o" ;
    //***********************
    //***********************
    if(isFilled(grid,6) == true)
    cout << "--"<<"o"<< "     Player 1 score: "<< playerScore(grid,1)<<endl;
    else
    cout << "  "<<"o"<< "     Player 1 score: "<< playerScore(grid,1)<<endl;
    //***********************
    //*************************
    if(isFilled(grid,7) == true)
    cout << "|";
    else
    cout << " " ;
    //*************************
    cout << "  ";
    //*************************
    if(isFilled(grid,8) == true)
    cout << "|";
    else
    cout << " " ;
    //*************************
    cout << "  ";
    //*************************
    if(isFilled(grid,9) == true)
    cout << "|";
    else
    cout << " ";
    //*************************
    cout << "  ";
    //*************************
    if(isFilled(grid,10) == true)
    cout << "|"<< endl;
    else
    cout << " " << endl;
    //*************************
    cout << "o";
    //***********************
    if(isFilled(grid,11) == true)
    cout << "--" << "o";
    else
    cout << "  "<<"o";
    //***********************
    //***********************
    if(isFilled(grid,12) == true)
    cout << "--" <<"o";
    else
    cout << "  "<<"o" ;
    //***********************
    //***********************
    if(isFilled(grid,13) == true)
    cout << "--"<<"o"<< "     Player 2 score: "<< playerScore(grid,2)<<endl;
    else
    cout << "  "<<"o"<< "     Player 2 score: "<< playerScore(grid,2)<<endl;
    //***********************
    cout <<"   ";
    //************************
    if(isFilled(grid,14) == true)
    cout << "|";
    else
    cout << " ";
    //*************************
    cout << "  ";
    //*************************
    if(isFilled(grid,15) == true)
    cout << "|"<< endl;
    else
    cout << " " << endl;
    //*************************
    cout << "   o";
    //***********************
    if(isFilled(grid,16) == true)
    cout << "--";
    else
    cout << "  ";
    //***********************
    cout <<  "o   " << std::endl;

}

long long Fill(long long grid,int move){
  long long add = 1;
  move = 18 - move;
  for (int i = 1; i <= move ; i++){
    add = add * 10;
  }
  //std::cout << grid + add << std::endl;
  return (grid + add);
}


void updateGrid(long long &grid,int pos,int p){

  bool extra_turn = false;
  bool new_form1,new_form2,new_form3,new_form4,new_form5 = true;

  if(isFilled(grid,1)&&isFilled(grid,2)&&isFilled(grid,3)&&isFilled(grid,5)){
    new_form1 = false;
  } else new_form1 = true;
  if(isFilled(grid,4)&&isFilled(grid,7)&&isFilled(grid,8)&&isFilled(grid,11)){
    new_form2 = false;
  }else new_form2 = true;
  if(isFilled(grid,5)&&isFilled(grid,8)&&isFilled(grid,9)&&isFilled(grid,12)){
    new_form3 = false;
  }else new_form3 = true;
  if(isFilled(grid,6)&&isFilled(grid,9)&&isFilled(grid,13)&&isFilled(grid,10)){
    new_form4 = false;
  }else new_form4 = true;
  if(isFilled(grid,12)&&isFilled(grid,14)&&isFilled(grid,15)&&isFilled(grid,16)){
    new_form5 = false;
  }else new_form5 = true;

  grid = Fill(grid,pos);

  if(isFilled(grid,1)&&isFilled(grid,2)&&isFilled(grid,3)&&isFilled(grid,5)&& new_form1 ){
    add_score(grid,p);
    extra_turn = true;
  }
  if(isFilled(grid,4)&&isFilled(grid,7)&&isFilled(grid,8)&&isFilled(grid,11)&& new_form2 ){
    add_score(grid,p);
    extra_turn = true;
  }
  if(isFilled(grid,5)&&isFilled(grid,8)&&isFilled(grid,9)&&isFilled(grid,12)&&new_form3){
    add_score(grid,p);
    extra_turn = true;
  }
  if(isFilled(grid,6)&&isFilled(grid,9)&&isFilled(grid,13)&&isFilled(grid,10)&&new_form4){
    add_score(grid,p);
    extra_turn = true;
  }
  if(isFilled(grid,12)&&isFilled(grid,14)&&isFilled(grid,15)&&isFilled(grid,16)&&new_form5){
    add_score(grid,p);
    extra_turn = true;
  }
  return;
}

int gameState(long long grid){
  if(playerScore(grid,1)+playerScore(grid,2) == 5){
    if(playerScore(grid,1)>playerScore(grid,2)) {
      //cout << "Player 1 wins!" <<endl;
      return 1;
    }else {
      //cout << "Player 2 wins!"<<endl;
      return 2;
    }
  }else return 3;
}

int main(int argc, char const *argv[]) {
  long long old_grid,grid = 0;
  int move;
  int player = 1;
  while (gameState(grid) == 3) {
    std::cout << grid << std::endl;
    displayGrid(grid);
    if(player == 1) cout << "Player 1, make your move (1-16):" ;
    else std::cout << "Player 2, make your move (1-16):" ;
    cin >> move;
    if(move > 16 || move < 1 || (isFilled(grid,move) == true)){
      std::cout << "Invalid move! Try again." << std::endl;
      continue;
    }else {
      old_grid = grid;
      updateGrid(grid, move , player);
      if(playerScore(grid,player)== playerScore(old_grid,player)) {
        if(player == 1) player = 2;
        else player = 1;
      }else {
        player = player;
        cout << "Player " << player << " scores! Gets an extra turn."<<endl;
      }
      old_grid = grid;
    }

  }
  displayGrid(grid);
  if(playerScore(grid,1)>playerScore(grid,2)) {
    cout << "Player 1 wins!" <<endl;
  }else {
    cout << "Player 2 wins!"<<endl;
  }
  return 0;
}
