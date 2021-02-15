// Joshua Carbajal
// lab7.cpp
// 3/3/2019
// Purpose: Creates a dynamically allocated two-dimensional array.
//				The size of the array depends on input from the user.
//				The elements are filled with random integers ranging
//				from 1-10. The contents of the array, sum of each row, 
//				column and major diagonals are printed to the user.
//				Then offers to repeat this as many times as they wish.

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void fillArray(int **array, int size);
// fills array with random integers

void deleteArray(int **array, int size);
// deletes memory

void printArray(int **array, int size);
// prints the contents of the array

void printRowSums(int **array, int size);
// prints all the row sums

void printColSums(int **array, int size);
// prints all the column sums

void printdiagSum(int **array, int size);
// prints the sums of the diagonals

int main() {
  	const char YES = 'y';
  	int size;
  	char again = YES;

	// repeat program until user wishes to stop
  	while (again == YES) {
	 	cout << "\nPlease enter an integer between 1 and 10. This will be\n"
		     << "the number of rows and columns for a 2D array: ";
    	cin >> size;

	 	// dynamically allocated two-dimensional array of integers
    	int **intArray;
    	intArray = new int*[size];
    	for (int i = 0; i < size; i++) 
      	intArray[i] = new int[size];
    
	 	// Fill all elements of the array with random integers
    	fillArray(intArray, size);

	 	// Print the array contents along with the sum of each each row, 
	 	// column and major diagonals
	 	printArray(intArray, size);
	 	printRowSums(intArray, size);
    	printColSums(intArray, size);
    	printdiagSum(intArray, size);

	 	// deallocate memory
	 	deleteArray(intArray, size);

	 	// ask user if they want to create another 2D array
    	cout << "Try again (y/n)? "; 
		cin >> again;
  }
  return 0;
}

void fillArray(int **array, int size) {
  	srand(time(NULL));
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			int num = rand() % 10 + 1; // random int from 1 - 10
			array[row][col] = num;
		}
	}		
}

void deleteArray(int **array, int size) {
  	for (int i = 0; i < size; i++) {
		delete [] array[i];
	}
	delete [] array;
}

void printArray(int **array, int size) {  
  	const char SPACE = ' ';
  	const char BAR = '|';
  	cout << endl;
  	for (int i = 0; i <= size; i++) {
   	if (i != 0)
			cout << setw(4) << (i - 1) << SPACE << BAR;
   	else // displays the row labels
     		cout << setw(6) << SPACE;
   	for (int j = 0; j < size; j++) {
     		if (i == 0) // displays the column labels
				cout << setw(4) << j << SPACE << BAR;
     		else
				cout << setw(4) << array[i-1][j] << SPACE << BAR; 
   	} 
    	cout << endl;  
  	}  
  	cout << endl;  
}

void printRowSums(int **array, int size) { 
  	cout << "The sums of each row:\n";
	for (int row  = 0; row < size; row++) {
		int sum = 0;
		for (int column = 0; column < size; column++) {
			sum += array[row][column];
		}
		cout << "Row " << row << ": " << sum << "\n";
	}
	cout << "\n";
}

void printColSums(int **array, int size) {
  	cout << "The sums of each column:\n"; 
	for (int column = 0; column < size; column++) {
		int sum = 0;
		for (int row = 0; row < size; row++) {
			sum += array[row][column];
		}
		cout << "Column " << column << ": " << sum << "\n";
	}
	cout << "\n";
}

void printdiagSum(int **array, int size) {
	cout << "The diagonal sums:\n";
	// First diagonal
	int sum1 = 0;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (row == col) {
				sum1 += array[row][col];
			}
		}
	}
	cout << "Left to right descending: " << sum1 << endl;
	// Second diagonal
	int sum2 = 0;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (row + col == (size - 1)) {
				sum2 += array[row][col];
			}
		}
	}
	cout << "Left to right ascending: " << sum2 << endl;
	cout << "\n";;
} 
