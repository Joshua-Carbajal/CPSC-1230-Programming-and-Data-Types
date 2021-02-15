// Joshua Carbajal
// p3.cpp
// 3/5/2019
// Purpose: Creates a interactive Tic Tac Toe game for users to play.
// Input: Users are asked for input on playing each piece. 
// Process: Played piece is verified and determines if there is a winner
// Output: Game statistics are displayed after each win or tie along with 
//			  if the user wishes to play again.

#include "tictactoe.h"

void displayStatistics(int, int, int);
// Purpose: Displays game information after each game
// IN: Number of wins for both players and ties.
// MODIFY: Updates game statistics.
// OUT:  Game statistics are displayed after each win
//			along with if the user wishes to play again.

int main()
{
	char reply = 'y'; // Answer from user to play again
	bool player = true; // Determines player turn 
	int winsX = 0; // Counter for X's wins 
	int winsO = 0; // Counter for O's wins
	int ties = 0; // Counter for tie games
	int row; // Placeholder for row in 2D array
	int col; // Placeholder for column in 2D array
	char marker; // Play piece
	
	TicTacToe board;
   board.welcomeMessage();
	while (reply == 'y') {
		int turn = 1; // counter
		board.resetBoard();
      while (!board.winner(marker) && turn < 9) {
			board.displayBoard();
			if (player) { 
				marker = 'X';
				cout << marker << ", it is your turn. \n";
				cout << "Which row? ";
				cin >> row;
				cout << "Which column? ";
				cin >> col;
				if(board.placeMarker(marker, row, col)) { 
					player = false;
				}
			} else {
				marker = 'O';
				cout << marker << ", it is your turn. \n";
				cout << "Which row? ";
				cin >> row;
				cout << "Which column? ";
				cin >> col;
				if(board.placeMarker(marker, row, col)) {
					player = true;
				}
			}
         board.winner(marker); 
			turn++;
      }
		if (board.winner(marker) && marker == 'X') {
			cout << "X won! Congratulations! \n";
			winsX++;
		} else if (board.winner(marker) && marker == 'O') {
			cout << "O won! Congratulations! \n";
			winsO++;
		} else if (turn == 9) {
			cout << "No winner, it was a tie! \n";
			ties++;
		}
      board.displayBoard();
      displayStatistics(winsX, winsO, ties);
      cout << "Do you want to play again? ";
		cin >> reply;
	}
   board.goodbyeMessage(); 
}

void displayStatistics(int winsX, int winsO, int ties) {
	cout << "\n \n";
	cout << "Game Stats \n";
	cout << "X has won " << winsX << " games. \n";
	cout << "O has won " << winsO << " games. \n";
	cout << "There have been " << ties << " tie games. \n";
}

