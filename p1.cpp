// Joshua Carbajal
// p1.cpp
// 1/23/2019
/* Purpose: Program takes a data file and interprets the data, 
searching for key values, sorts in ascending order
and searches again for those same key values. Printing these
values and array throughout these operations.
*/
// Input: Data file input by the user
// Process: Prints the array with data from file,
//          Performs (linear and binary) search algorithms for specific
//          values as well as sorting the array in ascending order. 
// Output: Prints results of search algorithm results to the user
//         for each operation and target values specified.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void print(int [],int);
// Purpose: To print out contents of array to user
// IN: The array and the number of values within the array
// MODIFY: None
// OUT: Printed values of array from data file

int linearSearch(int [], int, int);
// Purpose: To search for specified target values
// IN: The array along with specified target values 
// MODIFY: None
// OUT: Returns index, if found of target values (first occurence)

int binarySearch(int [], int, int);
// Purpose: Searches sorted array for target values
// IN: Array along with specified target values
// MODIFY: None
// OUT: Returns index, if found of target values (first occurence)

void selectionSort(int [], int);
// Purpose: Sorts array in ascending order
// IN: Array along with number of populated elements
// MODIFY: Sorts array in ascending order
// OUT: None

void checkSearch(int, int);
// Purpose: To check if target values are found within array
// IN: Target values and target index
// MODIFY: None
// OUT: Prints message if target value was found or not

int main()
{
	cout << "\n";
	cout << "Welcome to the Search & Sort program! \n";
	cout << "This program takes an input file from the user, \n";
	cout << "creates an array, performs several different \n";
	cout << "operations and prints them to the user. \n";
	cout << "\n";
	string FILENAME; // File path entered by user
	cout << "Enter filename: ";
	getline(cin, FILENAME);
	ifstream infile;
	infile.open(FILENAME);
	int numElements = 0; // Array counter
	const int KEY1 = 5; // Constant target value
	const int KEY2 = 10; // Constant target value
	const int SIZE = 20; // Preset length for array
	if (infile) {
		int num; // Data file counter
		int arr[SIZE]; // Preset length array used for data file values
		while (infile >> num) {
			arr[numElements] = num;
			numElements++;
		}
		cout << "\n";
		cout << "Print array results... \n";
		print(arr, numElements);
		cout << "\n";
		cout << "Search for keys using linear search... \n";
		int index1 = linearSearch(arr, numElements, KEY1);
		int index2 = linearSearch(arr, numElements, KEY2);
		checkSearch(KEY1, index1);
		checkSearch(KEY2, index2);
		cout << "\n";
		cout << "Sort array using selection sort & print array... \n";
		selectionSort(arr, numElements);
		print(arr, numElements);
		cout << "\n";
		cout << "Search for keys using binary search... \n";
		int val1 = binarySearch(arr, numElements, KEY1);
		int val2 = binarySearch(arr, numElements, KEY2);
		checkSearch(KEY1, val1);
		checkSearch(KEY2, val2);
		cout << "\n";
		cout << "Thanks for using the Search & Sort program! \n";
		cout << "\n";
	} else if (numElements == 0) {
		cout << "File has no values. \n";
	} else {
		cout << "Error opening the file. \n";
	}
	infile.close();
}

void print(int arr[], int numElements) 
{
	for (int i = 0; i < numElements; i++) {
		cout << "arr[" << i << "]: " << arr[i] << "\n";
	}
}

int linearSearch(int arr[], int numElements, int key)
{
	for (int index = 0; index < numElements; index++) {
		if (arr[index] == key) {
		   	return index;
	   	}
	}
	
	return -1;
}

int binarySearch(int arr[], int numElements, int key)
{
	int left = 0; // First index of array
	int right = numElements - 1; // Last index of array
	while(left <= right) {
		int middle = (left + right) / 2; // Middle index of array
		if (arr[middle] == key) {
			return middle;
		} else if (arr[middle] < key) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}
	
	return -1;
}

void selectionSort(int arr[], int numElements)
{
	for (int a = 0; a < numElements; a++) {
		
		for (int b = a + 1; b < numElements; b++) {
			
			if (arr[b] < arr[a]) {
				int temp = arr[a]; // Temporary place holder
				arr[a] = arr[b];
				arr[b] = temp;
			}
			
		}
		
	}
	
}

void checkSearch(int key, int value)
{
	if (value == -1) {
		cout << key << " not found. \n";
	} else {
		cout << key << " found at index " << value << "\n";
	}
}

