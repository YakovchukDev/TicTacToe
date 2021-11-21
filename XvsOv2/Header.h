#include <iostream>
#include <cstring>
#include <conio.h>
#include <ctime>
using namespace std;

void printf_board(char * board, bool &error, char choice_player);

void input_coordinate(int & move);

void move_(bool &error, char * board, int move, char choice_player, int &full_move);


void bot(int &full_move, char * board, char choice_bot);

void win_player(char * board, bool &error, char choice_player);

void win_bot(char * board, bool &error, char choice_player);