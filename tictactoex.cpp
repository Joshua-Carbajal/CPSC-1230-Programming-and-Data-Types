// Joshua Carbajal
// tictactoex.cpp
// 3/5/2019
// Purpose: Implementation file for TicTacToe class used to 
//				display messages, construct TicTacToe board and 
//				place pieces on board as well as check for a winner
//				display the board statistics.

#include "tictactoex.h"

TicTacToe::TicTacToe() {
	size = 3;
   board = new char*[size];
   for (int i = 0; i < size; i++) { 
      board[i] = new char[size];
	}
	for (int row = 0; row < size; row++) { 
		for (int col = 0; col < size; col++) {
			board[row][col] = SPACE;
		}
	}
}

TicTacToe::TicTacToe(int s) {
	size = s;
   board = new char*[size];
   for (int i = 0; i < size; i++) { 
      board[i] = new char[size];
	}
	for (int row = 0; row < size; row++) { 
		for (int col = 0; col < size; col++) {
			board[row][col] = SPACE;
		}
	}
}


void TicTacToe::resetBoard(int s) {
	size = s;
	for (int row = 0; row < size; row++) { 
		for (int col = 0; col < size; col++) {
			board[row][col] = SPACE;
		}
	}
}

void TicTacToe::displayBoard(int s) {
	size = s;
	cout << endl << endl;    
   for (int i = 0; i < COL_WIDTH - 1; i++)   
      cout << SPACE;    
   for (int i = 0; i < size; i++)    
      cout << setw(COL_WIDTH) << i;    
		cout << endl;    
   for (int r = 0; r < size; r++) {    
      cout << setw(COL_WIDTH) << r;    
      for (int c = 0; c < size; c++)     
         cout << SPACE << board[r][c] << VERTICAL;    
			cout << endl;    
      for (int i = 0; i < COL_WIDTH; i++)    
         cout << SPACE;                 
      for (int d = 0; d < size * COL_WIDTH; d++)    
         cout << DASH;                              
			cout << endl;       
   }
}

TicTacToe::~TicTacToe() {
	size = 3;
	for (int i = 0; i < size; i++) {
		delete [] board[i];
	}
	delete [] board;
}

TicTacToe::TicTacToe(const TicTacToe &obj) {
	size = 3;
	board = new char*[size];
   for (int i = 0; i < size; i++) {
      board[i] = new char[size];
	}
	for (int row = 0; row < size; row++) { 
		for (int col = 0; col < size; col++) {
			board[row][col] = obj.board[row][col];
		}
	}
}

TicTacToe& TicTacToe::operator=(const TicTacToe &obj) {
	size = 3;
	if (this != &obj) {
		for (int i = 0; i < size; i++) {
			delete [] board[i];
		}
		delete [] board;
		board = new char*[size];
		for (int i = 0; i < size; i++) { 
			board[i] = new char[size];
		}
		for (int row = 0; row < size; row++) { 
			for (int col = 0; col < size; col++) {
				board[row][col] = obj.board[row][col];
			}
		}
	}
	return *this;
}

bool TicTacToe::placeMarker(char marker, int row, int col, int s) {
	size = s;
	if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ') {
		board[row][col] = marker;
		return true;
	} else {
		cout << "Bad location, try again...\n";
		return false;
	}
}

bool TicTacToe::winner(char marker, int s) {
	size = s;
	for (int row = 0; row < size; row++) {
		int count = 0; // Counter
		for (int col = 0; col < size; col++) {
			if (board[row][col] == marker) {
				count++;
			}
		}
		if (count == size) {
			return true;
		}
	}
	
	for (int col = 0; col < size; col++) {
		int count = 0; // Counter
		for (int row = 0; row < size; row++) {
			if (board[row][col] == marker) {
				count++;
			}
		}
		if (count == size) {
			return true;
		}
	}
	
	int countDiag1 = 0; // Counter
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if ((row == col) && board[row][col] == marker) {
				countDiag1++;
			}
		}
		if (countDiag1 == size) {
			return true;
		}
	}
	
	int countDiag2 = 0; // Counter
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if ((row + col) == (size - 1) && board[row][col] == marker) {
				countDiag2++;
			}
		}
		if (countDiag2 == size) {
			return true;
		}
	}
	return false;
}


