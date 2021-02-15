// Joshua Carbajal
// tictactoe.cpp
// 3/5/2019
// Purpose: Implementation file for TicTacToe class used to 
//				display messages, construct TicTacToe board and 
//				place pieces on board.As well as check for a winner
//				after each turn and display the board statistics
//				once a game has been won.

#include "tictactoe.h"

void TicTacToe::welcomeMessage() {
	cout << "\n \n \n \n \n";
	cout << "Welcome to TicTacToe! This program allows the user to \n";
	cout << "play a interactice game of TicTacToe against an opponent \n";
	cout << "as many times as they would like. After every game \n";
	cout << "the program provides statistics on how you both did. \n";
	cout << "\n \n";
}

void TicTacToe::goodbyeMessage() {
	cout << "\n \n";
	cout << "Thanks for playing TicTacToe...goodbye!\n";
	cout << "\n";
}

TicTacToe::TicTacToe() {
   board = new char*[SIZE];
   for (int i = 0; i < SIZE; i++) { 
      board[i] = new char[SIZE];
	}
	for (int row = 0; row < SIZE; row++) { 
		for (int col = 0; col < SIZE; col++) {
			board[row][col] = SPACE;
		}
	}
}

void TicTacToe::resetBoard() {
	for (int row = 0; row < SIZE; row++) { 
		for (int col = 0; col < SIZE; col++) {
			board[row][col] = SPACE;
		}
	}
}

void TicTacToe::displayBoard() {
	cout << endl << endl;    
   for (int i = 0; i < COL_WIDTH - 1; i++)   
      cout << SPACE;    
   for (int i = 0; i < SIZE; i++)    
      cout << setw(COL_WIDTH) << i;    
		cout << endl;    
   for (int r = 0; r < SIZE; r++) {    
      cout << setw(COL_WIDTH) << r;    
      for (int c = 0; c < SIZE; c++)     
         cout << SPACE << board[r][c] << VERTICAL;    
			cout << endl;    
      for (int i = 0; i < SIZE; i++)    
         cout << SPACE;                 
      for (int d = 0; d < SIZE * COL_WIDTH; d++)    
         cout << DASH;                              
			cout << endl;       
   }
}

TicTacToe::~TicTacToe() {
	for (int i = 0; i < SIZE; i++) {
		delete [] board[i];
	}
	delete [] board;
}

TicTacToe::TicTacToe(const TicTacToe &obj) {
	board = new char*[SIZE];
   for (int i = 0; i < SIZE; i++) {
      board[i] = new char[SIZE];
	}
	for (int row = 0; row < SIZE; row++) { 
		for (int col = 0; col < SIZE; col++) {
			board[row][col] = obj.board[row][col];
		}
	}
}

TicTacToe& TicTacToe::operator=(const TicTacToe &obj) {
	if (this != &obj) {
		for (int i = 0; i < SIZE; i++) {
			delete [] board[i];
		}
		delete [] board;
		board = new char*[SIZE];
		for (int i = 0; i < SIZE; i++) { 
			board[i] = new char[SIZE];
		}
		for (int row = 0; row < SIZE; row++) { 
			for (int col = 0; col < SIZE; col++) {
				board[row][col] = obj.board[row][col];
			}
		}
	}
	return *this;
}

bool TicTacToe::placeMarker(char marker, int row, int col) {
	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
		board[row][col] = marker;
		return true;
	} else {
		cout << "Bad location, try again...\n";
		return false;
	}
}

bool TicTacToe::winner(char marker) {
	for (int row = 0; row < SIZE; row++) {
		int count = 0; // Counter
		for (int col = 0; col < SIZE; col++) {
			if (board[row][col] == marker) {
				count++;
			}
		}
		if (count == SIZE) {
			return true;
		}
	}
	
	for (int col = 0; col < SIZE; col++) {
		int count = 0; // Counter
		for (int row = 0; row < SIZE; row++) {
			if (board[row][col] == marker) {
				count++;
			}
		}
		if (count == SIZE) {
			return true;
		}
	}
	
	int countDiag1 = 0; // Counter
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			if ((row == col) && board[row][col] == marker) {
				countDiag1++;
			}
		}
		if (countDiag1 == SIZE) {
			return true;
		}
	}
	
	int countDiag2 = 0; // Counter
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			if ((row + col) == (SIZE - 1) && board[row][col] == marker) {
				countDiag2++;
			}
		}
		if (countDiag2 == SIZE) {
			return true;
		}
	}
	return false;
}

 
