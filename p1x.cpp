// Joshua Carbajal
// p1x.cpp
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

bool readFile(int [], int &);
// Purpose: Asks user for file path and populates array from data 
// IN: Array and number of values from data file (referenced)
// MODIFY: None
// OUT: Returns true if file open/read; otherwise returns false

void print(int [],int);
// Purpose: To print out contents of array to user
// IN: The array and the number of values within the array
// MODIFY: None
// OUT: Printed values of array from data file

int smallest(int [], int);
// Purpose: Find smallest values in array
// IN: Array and number of elements within it
// MODIFY: None
// OUT: Returns first index occurence of smallest value

int largest(int [], int);
// Purpose: Find largest value in array
// IN: Array and number of elements within it
// MODIFY: None
// OUT: Returns first index occurence of largest value

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
	cout << "This program takes an input file from the user, creates \n";
	cout << "an array, performs several different operations and \n";
	cout << "prints them to the user. \n";
	cout << "\n";
	int numElements = 0; // Array counter
	const int SIZE = 20; // Preset length for array
	int arr[SIZE]; // Preset length array used for data file values
	bool open = readFile(arr, numElements);
	if (!open) {
		cout << "Error opening the file. \n";
	} else if (numElements == 0) {
		cout << "File has no values. \n";
	} else {
		cout << "\n";
		cout << "Print array results... \n";
		print(arr, numElements);
		cout << "\n";
		int min = smallest(arr, numElements);
		cout << "Smallest value in the array: " << min << "\n";
		int max = largest(arr, numElements);
		cout << "Largest value in the array: " << max << "\n";
		cout << "\n";
		cout << "Search for keys using linear search... \n";
		for (int key = min; key <= max; key+=5) {
			int index = linearSearch(arr, numElements, key);
			checkSearch(key, index);
		}
		cout << "\n";
		cout << "Sort array using selection sort & print array... \n";
		selectionSort(arr, numElements);
		print(arr, numElements);
		cout << "\n";
		cout << "Search for keys using binary search... \n";
		for (int targetVal = min; targetVal <= max; targetVal+=5) {
			int targetIndex = binarySearch(arr, numElements, targetVal);
			checkSearch(targetVal, targetIndex);
		}
		cout << "\n";
		cout << "Thanks for using the Search & Sort program! \n";
		cout << "\n";
	}
}

bool readFile(int arr[], int &numElements) 
{
	string FILENAME; // File path entered by user
	cout << "Enter filename: ";
	getline(cin, FILENAME);
	ifstream infile;
	infile.open(FILENAME);
	if (infile) {
		int num; // Data file counter
		while (infile >> num) {
			arr[numElements] = num;
			numElements++;
		}
		
		return true; // File does open
		
    } else {
		
		return false; // File does not open
	}
    infile.close();
	
    return infile;
}
		
void print(int arr[], int numElements) 
{
	for (int i = 0; i < numElements; i++) {
		cout << "arr[" << i << "]: " << arr[i] << "\n";
	}
}

int smallest(int arr[], int numElements)
{
	int minVal = arr[0]; // Place holder, smallest value
	for (int a = 1; a < numElements; a++) {
		
		if (arr[a] < minVal) {
			minVal = arr[a];
		}
	}
	
	return minVal;
}

int largest(int arr[], int numElements) 
{
	int maxVal = arr[0]; // Place holder, largest value
	for (int b = 1; b < numElements; b++) {
		if (arr[b] > maxVal) {
			maxVal = arr[b];
		}
	}
	
	return maxVal;
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

void checkSearch(int key, int index)
{
	if (index == -1) {
		cout << key << " not found.\n";
	} else {
		cout << key << " found at index " << index << "\n";
	}
}
