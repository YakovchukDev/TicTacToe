#include "Header.h"

void printf_board(char * board, bool &error, char choice_player)
{
	system("CLS");
	cout << " " << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
	cout << endl << " " << (char)179 << " " << (char)218 << (char)196 << (char)196 << (char)196 << (char)194 << (char)196 << (char)196 << (char)196 << (char)194 << (char)196 << (char)196 << (char)196 << (char)191 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)179 << " " << board[6] << " " << (char)179 << " " << board[7] << " " << (char)179 << " " << board[8] << " " << (char)179 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)195 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)180 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)179 << " " << board[3] << " " << (char)179 << " " << board[4] << " " << (char)179 << " " << board[5] << " " << (char)179 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)195 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)180 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)179 << " " << board[0] << " " << (char)179 << " " << board[1] << " " << (char)179 << " " << board[2] << " " << (char)179 << " " << (char)179;
	cout << endl << " " << (char)179 << " " << (char)192 << (char)196 << (char)196 << (char)196 << (char)193 << (char)196 << (char)196 << (char)196 << (char)193 << (char)196 << (char)196 << (char)196 << (char)217 << " " << (char)179;
	cout << endl << " " << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;;
	if (error == true)
	{
		cout << endl << "ERROR: you can't put here " << choice_player << endl;
		error = false;
	}
	else cout << endl << endl;
}

void input_coordinate(int &move)
{
	cout << "Select a number: ";
	move = _getch();
}

void move_(bool &error, char * board, int move, char choice_player, int &full_move)
{
	if (board[move] != 'x' && board[move] != '0')
	{
		board[move] = choice_player;
		full_move++;
	}
	else error = true;
}

void bot(int &full_move, char * board, char choice_bot)
{
	int index;
	do
	{
		index = rand() % 9;
	} while (board[index] == 'x' || board[index] == '0');
	board[index] = choice_bot;
	full_move++;
}

void win_player(char * board, bool &error, char choice_player)
{
	printf_board(board, error, choice_player);
	cout << "      YOU WIN" << endl << endl;
}

void win_bot(char * board, bool &error, char choice_player)
{
	printf_board(board, error, choice_player);
	cout << "      YOU LOSE" << endl << endl;
}
