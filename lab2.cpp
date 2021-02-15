//Joshua Carbajal
//lab3.cpp
/*Purpose: Program asks user for two integers,
  then decides if the first integer is a multiple of
  the second integer.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int num1;
  int num2;
  cout << "Welcome to the Decisions program! \n";
  cout << "Enter two numbers, separated by a space: ";
  cin >> num1 >> num2;
  if (num2 == 0) {
    cout << "The second number cannot be zero. Please try again. \n";
  } else if (num1 < num2 || num1 % num2 != 0) {
    cout << num1 << " is NOT a multiple of " << num2 << ".\n";
  } else {
    cout << num1 << " is a multiple of " << num2 << " with a factor of " << num1 / num2 << ".\n";
  }
  cout << "Thanks for using the Decisions program! \n";
}
  
