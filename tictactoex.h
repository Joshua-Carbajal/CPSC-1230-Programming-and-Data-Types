// Joshua Carbajal
// tictactoex.h
// 3/5/2019
// Purpose: Specification file for the TicTacToe class used to display
//				messages, construct TicTacToe board, place pieces on the board
//				as well as check for a winner.

#ifndef TICTACTOEX_H
#define TICTACTOEX_H

#include <iostream>
#include <iomanip>

using namespace std;

class TicTacToe
{
	public:
		
		TicTacToe(); 
	   // Purpose: Default constructor
	   // Pre(conditions): None
	   // Post(conditions): All indeces of 2D array assigned ' '
		
		TicTacToe(int s); 
	   // Purpose: Default constructor with size input by user
	   // Pre(conditions): Valid size from 3 to 25, odd number
	   // Post(conditions): All indeces of 2D array assigned ' '
        
		void displayBoard(int s);
		// Purpose: Displays the game board to the user
	   // Pre(conditions): None
	   // Post(conditions): Game board is updated with values from user
		
      bool placeMarker(char marker, int row, int col, int s); 
		// Purpose: Places player's piece on the game board if valid location
	   // Pre(conditions): Row and column must be valid location
	   // Post(conditions): Returns true if valid else play same turn again 
		
      bool winner(char marker, int s); 
		// Purpose: Determines if there is a game won
	   // Pre(conditions): Character value played by user
	   // Post(conditions): Returns true if there is a winner, else game resumes
		
		~TicTacToe(); 
		// Purpose: Destructor
	   // Pre(conditions): Dynamically allocated 2D array
	   // Post(conditions): Deletes dynamically allocated 2D array
		
		TicTacToe(const TicTacToe &); 
		// // Purpose: Copy constructor
	   // // Pre(conditions):
	   // // Post(conditions):
		
		TicTacToe& operator=(const TicTacToe &); 
		// // Purpose: Overloaded operator
	   // // Pre(conditions):
	   // // Post(conditions):
      
		void resetBoard(int s);
		// Purpose: Resets the game board if game played again
	   // Pre(conditions): Dynamically allocated 2D array has been constructed
	   // Post(conditions): Sets all indeces of the 2D array back to ' '
		
	private:
		char **board; // Dynamically allocated 2D array
		static const char DASH = '-'; // Board construction piece
		static const char VERTICAL = '|'; // Board construction piece
		static const char SPACE = ' '; // Placeholder character
		static const int COL_WIDTH = 3; // Width of the game board
		int size;
		
};
#endif

