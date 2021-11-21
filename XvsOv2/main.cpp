#include "Header.h"

void game(char choice_player, char choice_bot)
{
	const int n = 9;
	char board[n];
	int move;
	int full_move = 0;
	bool error = false;
	bool win = false;

	for (int i = 0; i < n; i++)
	{
		board[i] = i + 1 + '0';
	}

	while (full_move < 9)
	{
		if (full_move % 2 == 0)
		{
			do
			{
				printf_board(board, error, choice_player);
				input_coordinate(move);
			} while (move < 49 || move > 57);

			switch ((char)move)
			{
			case '1':
			{
				move = 0;
				break;
			}
			case '2':
			{
				move = 1;
				break;
			}
			case '3':
			{
				move = 2;
				break;
			}
			case '4':
			{
				move = 3;
				break;
			}
			case '5':
			{
				move = 4;
				break;
			}
			case '6':
			{
				move = 5;
				break;
			}
			case '7':
			{
				move = 6;
				break;
			}
			case '8':
			{
				move = 7;
				break;
			}
			case '9':
			{
				move = 8;
				break;
			}
			}

			move_(error, board, move, choice_player, full_move);
		}
		else
		{
			bot(full_move, board, choice_bot);
		}

		if (error == false)
		{
			if ((board[6] == choice_player && board[7] == choice_player && board[8] == choice_player) || (board[3] == choice_player && board[4] == choice_player && board[5] == choice_player) || (board[0] == choice_player && board[1] == choice_player && board[2] == choice_player) || (board[6] == choice_player && board[3] == choice_player && board[0] == choice_player) || (board[7] == choice_player && board[4] == choice_player && board[1] == choice_player) || (board[8] == choice_player && board[5] == choice_player && board[2] == choice_player) || (board[6] == choice_player && board[4] == choice_player && board[2] == choice_player) || (board[0] == choice_player && board[4] == choice_player && board[8] == choice_player))
			{
				win = true;
				win_player(board, error, choice_player);
				break;
			}
			else if ((board[6] == choice_bot && board[7] == choice_bot && board[8] == choice_bot) || (board[3] == choice_bot && board[4] == choice_bot && board[5] == choice_bot) || (board[0] == choice_bot && board[1] == choice_bot && board[2] == choice_bot) || (board[6] == choice_bot && board[3] == choice_bot && board[0] == choice_bot) || (board[7] == choice_bot && board[4] == choice_bot && board[1] == choice_bot) || (board[8] == choice_bot && board[5] == choice_bot && board[2] == choice_bot) || (board[6] == choice_bot && board[4] == choice_bot && board[2] == choice_bot) || (board[0] == choice_bot && board[4] == choice_bot && board[8] == choice_bot))
			{
				win = true;
				win_bot(board, error, choice_player);
				break;
			}
		}
	}
	if (win == false)
	{
		printf_board(board, error, choice_player);
		cout << "     GAME OVER" << endl << endl;
	}

}

int main()
{
	srand(time(0));
	char choice_player;
	char choice_bot;
	do
	{
		system("CLS");
		cout << endl << "   You need choice X or 0";
		cout << endl << endl << "You choice: ";
		cin >> choice_player;
	} while (choice_player != 'x' && choice_player != 'X' && choice_player != '0' && choice_player != 'o' && choice_player != 'O');

	if (choice_player == 'x') choice_bot = '0';
	else choice_bot = 'x';

	system("CLS");
	cout << endl << "   use Num-lock for management" << endl  << endl;
	system("pause");

	int again;
	do
	{
		game(choice_player, choice_bot);
		cout << endl << "Do you want play again YES(y) or NO(n)" << endl;
		cout << "You choice: ";
		do
		{			
			again = _getch();
		} while ((char)again != 'y' && (char)again != 'n');
	} while ((char)again == 'y');
	cout << endl;
	system("pause");
}