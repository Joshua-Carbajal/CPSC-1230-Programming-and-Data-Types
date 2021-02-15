// Joshua Carbajal
// tictactoe.h
// 3/5/2019
// Purpose: Specification file for the TicTacToe class used to display
//				messages, construct TicTacToe board, place pieces on the board
//				as well as check for a winner.

#ifndef TICTACTOE_H
#define TICTACTOE_H

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
        
		void displayBoard();
		// Purpose: Displays the game board to the user
	   // Pre(conditions): None
	   // Post(conditions): Game board is updated with values from user
		
      bool placeMarker(char marker, int row, int col); 
		// Purpose: Places player's piece on the game board if valid location
	   // Pre(conditions): Row and column must be valid location
	   // Post(conditions): Returns true if valid else play same turn again 
		
      bool winner(char marker); 
		// Purpose: Determines if there is a game won
	   // Pre(conditions): Character value played by user
	   // Post(conditions): Returns true if there is a winner, else game resumes
		
		~TicTacToe(); 
		// Purpose: Deletes 2D array
	   // Pre(conditions): Dynamically allocated 2D array
	   // Post(conditions): Deletes dynamically allocated 2D array
		
		TicTacToe(const TicTacToe &); 
		// Purpose: Copies a 2D array from an original 2D array
	   // Pre(conditions): None
	   // Post(conditions): Dynamically allocates new 2D array board and
		// 						populates it with values from original 2D array
		
		TicTacToe& operator=(const TicTacToe &); 
		// Purpose: Copies a 2D array from an original 2D array
	   // Pre(conditions): Addresses must not be equal
	   // Post(conditions): Deletes 2D array copy, dynamically allocates new 
		//							2D array board and populates it with values from 
		//							original 2D array
		
      void welcomeMessage();
		// Purpose: Displays welcome message to user
	   // Pre(conditions): None
	   // Post(conditions): Prints welcome message
		  
      void goodbyeMessage();
		// Purpose: Displays goodbye message to user
	   // Pre(conditions): None
	   // Post(conditions): Prints goodbye message
      
		void resetBoard();
		// Purpose: Resets the game board if game played again
	   // Pre(conditions): Dynamically allocated 2D array has been constructed
	   // Post(conditions): Sets all indeces of the 2D array back to ' '
		
	private:
		char **board; // 2D character array
		static const char DASH = '-'; // Board construction piece
		static const char VERTICAL = '|'; // Board construction piece
		static const char SPACE = ' '; // Placeholder character
		static const int SIZE = 3; // Size of the game board
		static const int COL_WIDTH = 3; // Width of the game board
		
};
#endif
