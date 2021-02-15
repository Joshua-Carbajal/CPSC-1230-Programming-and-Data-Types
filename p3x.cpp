// Joshua Carbajal
// p3x.cpp
// 3/5/2019
// Purpose: Creates a interactive Tic Tac Toe game for users to play.
// Input: Users are initially asked the size of the board they would like to
//			 to play along with location for play pieces. 
// Process: Played piece is verified and determines if there is a winner
// Output: Game statistics are displayed after each win along with if the 
//			  users wishe to play again. If users wish to play again, they are 
//			  asked what size of board they would like to play on.

#include "tictactoex.h"

void welcomeMessage();
// Purpose: Display welcome message to user
// IN: None
// MODIFY: None
// OUT: Displays message before the first game played

void displayStatistics(int, int, int);
// Purpose: Displays game information after each game
// IN: Number of wins for both players and ties.
// MODIFY: Updates game statistics.
// OUT:  Game statistics are displayed after each win
//			along with if the user wishes to play again.

void goodbyeMessage();
// Purpose: Displays goodbye message to the user
// IN: None
// MODIFY: None
// OUT: Displays message after the last game is played 

int main()
{
	char reply = 'y'; // Answer from user to play again
	bool player = true; // Determines player turn 
	int winsX = 0; // Counter for X's wins 
	int winsO = 0; // Counter for O's wins
	int ties = 0; // Counter for tie games
	int row; // Placeholder for rows in 2D array
	int col; // Placeholder for columns in 2D array
	char marker; // Play piece
	int s; // Size of board
	
	welcomeMessage();
	while (reply == 'y') {
		cout << "What size game do you want to play? ";
		cin >> s;
		cout << "\n \n";
		TicTacToe board(s);
		int turn = 1; // counter
		board.resetBoard(s);
      while (!board.winner(marker, s) && turn < (s * s)) {
			board.displayBoard(s);
			if (player) { 
				marker = 'X';
				cout << marker << ", it is your turn. \n";
				cout << "Which row? ";
				cin >> row;
				cout << "Which column? ";
				cin >> col;
				if(board.placeMarker(marker, row, col, s)) { 
					player = false;
				}
			} else {
				marker = 'O';
				cout << marker << ", it is your turn. \n";
				cout << "Which row? ";
				cin >> row;
				cout << "Which column? ";
				cin >> col;
				if(board.placeMarker(marker, row, col, s)) {
					player = true;
				}
			}
         board.winner(marker, s); 
			turn++;
      }
		if (board.winner(marker, s) && marker == 'X') {
			cout << "X won! Congratulations! \n";
			winsX++;
		} else if (board.winner(marker, s) && marker == 'O') {
			cout << "O won! Congratulations! \n";
			winsO++;
		} else if (turn == (s * s)) {
			cout << "No winner, it was a tie! \n";
			ties++;
		}
      board.displayBoard(s);
      displayStatistics(winsX, winsO, ties);
      cout << "Do you want to play again? ";
		cin >> reply;
		cin.ignore();
	}
   goodbyeMessage(); 
}

void welcomeMessage() {
	cout << "\n \n \n \n \n";
	cout << "Welcome to TicTacToe! This program allows the user to \n";
	cout << "play a interactice game of TicTacToe against an opponent \n";
	cout << "as many times as they would like. After every game \n";
	cout << "the program provides statistics on how you did. Your game \n";
	cout << "can be from size 3 to size 25, but it must be an odd number. \n";
}

void displayStatistics(int winsX, int winsO, int ties) {
	cout << "\n \n";
	cout << "Game Stats \n";
	cout << "X has won " << winsX << " games. \n";
	cout << "O has won " << winsO << " games. \n";
	cout << "There have been " << ties << " tie games. \n";
}

void goodbyeMessage() {
	cout << "\n \n";
	cout << "Thanks for playing TicTacToe...goodbye!\n";
	cout << "\n";
}


