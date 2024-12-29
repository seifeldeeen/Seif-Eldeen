#include <iostream>
using namespace std;
int player = 1;
int position = 0;
string row[9] = {" "," "," "," "," "," "," "," "," "};
void greet(){
cout << "welcome to tic tac toe game or\n";
cout << "as we call it x-o,you will play against\n";
cout << "your friend in this game,of course \n\n";
cout << "player 1 is x \n player 2 is o \n\n\n";
cout << "     |     |      \n";
cout << "  1  |  2  |  3   \n";
cout << "_____|_____|_____ \n";
cout << "     |     |      \n";
cout << "  4  |  5  |  6   \n";
cout << "_____|_____|_____ \n";
cout << "     |     |      \n";
cout << "  7  |  8  |  9   \n";
cout << "     |     |      \n\n";
}
bool is_winner(){
bool winner = false;
if ((row[0] == row[1]) && (row[1] == row[2]) && row[0] != " "){
winner = true;
}
else if ((row[3] == row[4]) && (row[3] == row[5]) && row[3] != " ") {
    winner = true;
  }
 else if ((row[6] == row[7]) && (row[6] == row[8]) && row[6] != " ") {
winner = true;
}
else if ((row[0] == row[3]) && (row[0] == row[6]) && row[0] != " ") {
   winner = true;
} 
else if ((row[1] == row[4]) && (row[1] == row[7]) && row[1] != " ") {
    winner = true;
  }
 else if ((row[2] == row[5]) && (row[2] == row[8]) && row[2] != " ") {
    winner = true;
  }
 else if ((row[0] == row[4]) && (row[0] == row[8]) && row[0] != " ") {  
winner = true;
}
 else if ((row[2] == row[4]) && (row[2] == row[6]) && row[2] != " ") { 
 winner = true;
}
return winner;
}
void draw(){
cout << "     |     |      \n";
cout << "  " << row[0] << "  |  " << row[1] << "  |  " << row[2] << "\n";
cout << "_____|_____|_____ \n";
cout << "     |     |      \n";
cout << "  " << row[3] << "  |  " << row[4] << "  |  " << row[5] << "\n";
cout << "_____|_____|_____ \n";
cout << "     |     |      \n";
cout << "  " << row[6] << "  |  " << row[7] << "  |  " << row[8] << "\n";
cout << "     |     |      \n";
cout << "\n";
}
bool fill(){
bool fills = true;
for (int i = 0; i < 9; i++){ 
if (row[i] == " ") {
 fills = false;
}
}
return fills;
}
void set() {
std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
while (!(std::cin >> position)) {
std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";

}
std::cout << "\n";
while (row[position-1] != " ") {
std::cout << "Oops, there's already something in that position!\n\n";
std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
std::cin >> position;
std::cout << "\n";
 }
}
void update_draw() {
 if (player % 2 == 1) {
  row[position-1] = "X";
} 
else {
   row[position-1] = "O";
 }
}
void change_player() {
 if (player == 1) {
  player++; 
} 
else {
   player--;
  }
}
void take_turn() {
while ( !is_winner() && !fill() ) 
{
 set(); 
 update_draw();
  change_player(); 
  draw();
  }
}
void end_game() {
 if (is_winner()) {
 std::cout << "There's a winner!\n"; 
}
  else if (fill()) {
 std::cout << "There's a tie!\n";
}
}
