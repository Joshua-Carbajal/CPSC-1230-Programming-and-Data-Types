// Joshua Carbajal
// Lab4.cpp
// 1/19/2019
/* Purpose: This program reads in a file and interprets the data. 
The values are sorted into 3 different arrays based on their values 
being postive/negative even numbers and negative numbers. 
The arrays are then printed out showing their values and 
respective indices.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string FILENAME;
	cout << "Enter the filename: ";
	getline(cin, FILENAME);
	cout << "\n";
	ifstream infile;
	infile.open(FILENAME);
	if (infile) {
		const int SIZE = 30;
		// All the arrays are now a preset length of 30
		int evenNum[SIZE];
		int oddNum[SIZE];
		int negNum[SIZE];
		int num;
		int a = 0, b = 0, c = 0, i = 0;
		while (infile >> num) {
			if (num > 0 && num % 2 == 0) {
				evenNum[a] = num;
				a++;
			} else if (num > 0 && num % 2 != 0) {
				oddNum[b] = num;
				b++;
			} else if (num < 0) {
				negNum[c] = num;
				c++;
			}
		}
		// Prints contents of array evenNum, if any values populated
		if (a > 0) {
			for (i = 0; i < a; i++) {
				cout << "evenNum[" << i << "]: " << evenNum[i] << "\n";
			}
		cout << "\n";
		}
		// Prints contents of array oddNum, if any values populated
		if (b > 0) {
			for (i = 0; i < b; i++) {
				cout << "oddNum[" << i << "]: " << oddNum[i] << "\n";
			}
		cout << "\n";
		}
		// Prints contents of array negNum, if any values populated
		if (c > 0) {
			for (i = 0; i < c; i++) {
				cout << "negNum[" << i << "]: " << negNum[i] << "\n";
			}
		cout << "\n";
		}
	} else {
		cout << "Could not open the file.\n";
	}
	infile.close();
}
		
			
			
	
