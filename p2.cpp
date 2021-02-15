// Joshua Carbajal
// p2.cpp
// 2/23/2019
//PURPOSE: Takes in a file from the user. Creates a linked list and 
//		   adds nodes in ascending order corresponding to the integer
//		   in each line of the file. Prints out message to the user.
// INPUT: Data file input by the user.
// PROCESS: Creates linked list with both character and integer values
//			from the file. Adds these nodes in ascending order based on 
//	 		the value of the integer in the line from the file.
// OUTPUT: Prints the message from the file and deletes the linked list.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node {
	char letter;
	int number;
	Node *next;
};

void addInOrder(Node *&, char, int);
// PURPOSE: Adds nodes in ascending order to linked list based
//			on the integer value within each line of the file.
// IN: Pointer node to start of linked list and single line values 
//     from file containing a character and integer.
// MODIFY: Creates and adds a new node in ascending order by the 
//         integer value to the linked list.
// OUT: A linked list with all nodes in ascending order.

void printMessage(Node *);
// PURPOSE: Prints the message to the user.
// IN: A pointer node to the start of the linked list.
// MODIFY: None
// OUT: Prints the contents of the linked list.

void deleteList(Node *&);
// PURPOSE: Deletes the linked list.
// IN: A pointer node to the start of the linked list.
// MODIFY: Points to next node in the list and deletes the previous one.
// OUT: The linked list deleted from memory.

int main()
{
	Node *head = nullptr; // Pointer to head of linked list
	char answer = 'y'; // Does the user want to continue?
	string filename; // Name of the file
	cout << "\nWelcome to the Secret Messages program. \n";
	cout << "This program take a file from the user and decodes a \n";
	cout << "secret message for the user to see. \n";
	while (answer == 'y') {
		cout << "\nEnter filename: ";
		getline(cin,filename);
		ifstream infile;
		infile.open(filename);
		if (infile) {
			string oneLine; // Contains one line from file
			while (getline(infile,oneLine)) {
				char singleLetter = oneLine.front(); // Character from line 
				string value = oneLine.substr(1); // String of integer value
				int singleNumber = stoi(value); // Converted integer value
				addInOrder(*&head, singleLetter, singleNumber);
			}
		} else {
			cout << "Error opening the file. \n";
		} 
		infile.close();
		cout << "\nSecret message: \n";
		printMessage(head);
		cout << "\n";
		cout << "\nTry again (y/n)? ";
		cin >> answer;
		cin.get();
		deleteList(*&head);
	}
	cout << "\nThanks for using the Secret Messages program! \n";
	cout << "\n";
}

void printMessage(Node *head) 
{
  Node *currNode = head; //Pointer to head of linked list
  while (currNode != nullptr) {
    cout << currNode->letter;
    currNode = currNode->next;
  }
}

void addInOrder(Node *&head, char singleLetter, int singleNumber) 
{
	Node *helper = head; // Pointer to head of linked list
	Node *prevNode = nullptr; // Pointer for previous node of linked list
	Node *newNode = new Node; // Pointer to node of newly allocated memory
	newNode->letter = singleLetter;
	newNode->number = singleNumber;
	if (head == nullptr) {
		head = newNode;
		newNode->next = nullptr;
	} else {
		while (helper != nullptr && helper->number < singleNumber) {
			prevNode = helper;
			helper = helper->next;
		}
	}
	if (prevNode == nullptr) {
		head = newNode;
		newNode->next = helper;
	} else {
		prevNode->next = newNode; 
		newNode->next = helper;
	}
}

void deleteList(Node *&head) 
{
	Node *helper; // Pointer to head of linked list
	while (head != nullptr) {
		helper = head;
		head = head->next;
		delete helper;
	}
}


 

		
	
		
	
	
