// Joshua Carbajal
// lab3.cpp
// Date: 1/18/2019
/* Purpose: This program takes two type double inputs from the user
   and displays them, swaps the values and then outputs those 
   swapped values.
*/
// Input: The user inputs two values of type double
// Process: The values entered are swapped
// Output: The values are printed out both before and after the swap occurs

#include <iostream>
using namespace std;

void input(double &val1, double &val2);
//Purpose: Asks the user for two values and "return" them to function main
//In: Two values from user that are type double
//Modify: None
//Output: Return values to function to be used by function swapVal and output

void swapVal(double &val1, double &val2);
//Purpose: To swap the values passed to it from function main
//In: Two values of type double passed by reference from function main
//Modify: Both values passed to it are interchanged with one another
//Output: Values are returned back to function main 

void output(double val1, double val2);
//Purpose: To print out the values passed into it 
//In: Two double values passed in from function main
//Modify: None
//Output: Prints out the values to the user

int main()
{
  double val1, val2;
  input(val1, val2);
  cout << "Before the swap, \n";
  output(val1, val2);
  swapVal(val1, val2);
  cout << "After the swap, \n";
  output(val1, val2);
}

void input(double &val1, double &val2) 
{
  double num1, num2;
  cout << "Please input the first double value: ";
  cin >> num1;
  val1 = num1;
  cout << "Please input the second double value: ";
  cin >> num2;
  val2 = num2;
}

void swapVal(double &val1, double &val2) 
{
  double extra = val1;
  val1 = val2;
  val2 = extra;
}

void output(double val1, double val2) 
{
  cout << "The values are " << val1 << " , " << val2 << ".\n";
}




  
