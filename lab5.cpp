// Joshua Carbajal
// Lab5.cpp
// 1/30/2019
/* Purpose: Creates a regular and pointer type variable,
   prints their values and addresses. Takes a number input 
   from the user and creates arrray with random values and 
   prints them to the user.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
  int num; // Declared regular variable
  int *pointer = nullptr; // Declared pointer variable
  
  //1 Ask user for value and stores it in the regular variable
  cout << "Enter a number: ";
  cin >> num;
  
  //2 Make pointer variable point to regular variable
  pointer = &num;
  
  //3 Print values and addresses of both regular and pointer variable
  cout << num << " " << &num << " " << *pointer << " " << pointer << "\n";
  
  //4 Allocate memory for pointer for a single value
  pointer = new int;
  
  //5 Store a value into newly allocated memory
  *pointer = 17;
  
  //6 Print values and addresses of both regular and pointer variable
  cout << num << " " << &num << " " << *pointer << " " << pointer << "\n";
  
  //7 Deallocate memory that was previously allocated
  delete pointer;
  
  //8 Ask user for number to allocate memory for new array
  //  that is of the same size as number input
  int sizeArray; // Declared size of the array
  cout << "Enter the size of the array: ";
  cin >> sizeArray;
  int *arrPtr = new int[sizeArray]; // Newly allocated memory array created
  
  //9 Store random values into newly allocated array
  srand(time(NULL)); // Initialize random seed
  for (int i = 0; i < sizeArray; i++) {
	int randNum = rand() % 25 + 1; // Creates random number (1 to 25)
	*(arrPtr + i) = randNum;
  }
  
  //10 Print all elements of the array
  for (int j = 0; j < sizeArray; j++) {
	  cout << *(arrPtr + j) << " ";
  }
  
  cout << "\n";
  
  //11 Delete allocated memory of pointer array
  delete [] arrPtr;
}
