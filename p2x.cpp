// Joshua Carbajal
// p2x.cpp
// 2/23/2019
// PURPOSE: Takes two files from the user and creates linked lists with 
//			nodes in ascending order correspoding to the integer in each line 
//			of the file. Prints out individual messages from each 
//			individual file. Merges the two messages and prints out a final 
//			message.
// INPUT: Two files input by the user
// PROCESS: Creates linked lists with both character and integer values
//			from both files. Adds these nodes in ascending order based on 
//	 		the value of the integer in each line of their respective file. 
//			Merges both messages together taking words from every other 
//			message and combining them togther to form a single message.
// OUTPUT:	Prints the message from the two files along with the 
//			merged message from both files together and then deletes 
//			the linked lists.

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

void merge(Node *&, Node *&, Node *&);
// PURPOSE: Merges both secret message linked lists together into another 
//			linked list taking one word from each at a time. Appends the 
//			end of either secret message linked list if one is longer
//			than the other.
// IN: The pointer node to the start of each linked list of its respective 
//	   file from the user along with a pointer node to the start of the 
//	   linked list that merges both linked lists together.
// MODIFY: Takes both messages and merges them together taking words one 
//		   at a time from each individual message. 
// OUT: A linked list merged from both linked lists created previously.

int main()
{
	Node *head1 = nullptr; //Pointer to head of first linked list
	Node *head2 = nullptr; //Pointer to head of second linked list
	Node *mergedHead = nullptr; //Pointer to head of merged linked list
	char answer = 'y'; //Does the user want to continue?
	string filename1; //Name of the first file
	string filename2; //Name of the second file
	cout << "\nWelcome to the Secret Messages program. \n";
	cout << "This program takes two files from the user and decodes a \n";
	cout << "secret message from each one for the user to see. Then \n";
	cout << "merges the two messages to create a whole new message! \n";
	while (answer == 'y') {
		cout << "\nEnter filename #1: ";
		getline(cin,filename1);
		cout << "Enter filename #2: ";
		getline(cin,filename2);
		ifstream infile;
		
		//First secret message
		infile.open(filename1);
		if (infile) {
			string oneLine; //Contains one line from file
			while (getline(infile,oneLine)) {
				char singleLetter = oneLine.front(); //Character from line 
				string value = oneLine.substr(1); //String of integer value
				int singleNumber = stoi(value); //Converted integer value
				addInOrder(*&head1, singleLetter, singleNumber);
			}
		} else {
			cout << "Error opening the file \n";
		} 
		infile.close();
		cout << "\nSecret message #1: \n";
		printMessage(head1);
		cout << "\n";
		
		//Second secret message
		infile.open(filename2);
		if (infile) {
			string oneLine; //Contains one line from file
			while (getline(infile,oneLine)) {
				char singleLetter = oneLine.front(); //Character from line 
				string value = oneLine.substr(1); //String of integer value
				int singleNumber = stoi(value); //Converted integer value
				addInOrder(*&head2, singleLetter, singleNumber);
			}
		} else {
			cout << "Error opening the file \n";
		} 
		infile.close();
		cout << "\nSecret message #2: \n";
		printMessage(head2);
		cout << "\n";
		
		//Merged message
		merge(*&head1, *&head2, *&mergedHead);
		cout << "\nMerged secret message: \n";
		printMessage(mergedHead);
		cout << "\n";
		cout << "\nTry again (y/n)? ";
		cin >> answer;
		cin.get();
		deleteList(*&head1);
		deleteList(*&head2);
		deleteList(*&mergedHead);
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
	Node *helper = head; //Pointer to head of linked list
	Node *prevNode = nullptr; //Pointer to previous node of linked list
	Node *newNode = new Node; //Pointer to node of newly allocated memory
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
	Node *helper; //Pointer to head of linked list
	while (head != nullptr) {
		helper = head;
		head = head->next;
		delete helper;
	}
}

void merge(Node *&head1, Node *&head2, Node *&mergedHead) 
{
	Node *firstHelper = head1; //Pointer to head of first linked list
	Node *secondHelper = head2; //Pointer to head of second linked list
	while (firstHelper != nullptr && secondHelper != nullptr) {
		//Gets word from first linked list
		while (firstHelper->letter != ' ') {
			Node *newNode = new Node; //Pointer to node of newly allocated memory
			newNode->letter = firstHelper->letter;
			newNode->number = 0;
			newNode->next = nullptr;
			if (mergedHead == nullptr) {
				mergedHead = newNode; 
			} else {
				Node *helper = mergedHead; //Pointer to head of merged linked list
				while (helper->next != nullptr) {
					helper = helper->next;
				}
				helper->next = newNode;
			} 
			firstHelper = firstHelper->next;
		}
		firstHelper = firstHelper->next;
		
		//Append space between words once its gone outside the first loop
		Node *firstSpace = new Node; //Pointer to node of newly allocated memory
		firstSpace->letter = ' ';
		firstSpace->number = 0;
		firstSpace->next = nullptr;
		Node *helperFirst = mergedHead; //Pointer to head of merged linked list
		while (helperFirst->next != nullptr) {
			helperFirst = helperFirst->next;
		}
		helperFirst->next = firstSpace;
		
		while(secondHelper->letter != ' ') {
			//Gets word from second linked list
			Node *newNode = new Node; //Pointer to node of newly allocated memory
			newNode->letter = secondHelper->letter;
			newNode->number = 0;
			newNode->next = nullptr;
			if (mergedHead == nullptr) {
				mergedHead = newNode;
			} else {
				Node *helper = mergedHead; //Pointer to head of merged linked list
				while (helper->next != nullptr) {
					helper = helper->next;
				}
				helper->next = newNode;
			}
            secondHelper = secondHelper->next;
		}
		secondHelper = secondHelper->next;
		
		//Append space between words once its gone outside second the loop
		Node *secondSpace = new Node; //Pointer to node of newly allocated memory
		secondSpace->letter = ' ';
		secondSpace->number = 0;
		secondSpace->next = nullptr;
		Node *helperSecond = mergedHead; //Pointer to head of merged linked list
		while (helperSecond->next != nullptr) {
			helperSecond = helperSecond->next;
		}
		helperSecond->next = secondSpace;
	}
	
	//Append extra words to end of merged message if one 
	//linked list still has words left over
	if (firstHelper != nullptr) {
		Node *h1 = firstHelper; //Pointer to head of first linked list
		while (h1 != nullptr) {
			//Append the end of first linked list
			Node *newNode = new Node; //Pointer to node of newly allocated memory
			newNode->letter = h1->letter;
			newNode->number = 0;
			newNode->next = nullptr;
			Node *mergeHelper = mergedHead;//Pointer to head of merged linked list
			while (mergeHelper->next != nullptr) {
				mergeHelper = mergeHelper->next;
			}
			mergeHelper->next = newNode;
			h1 = h1->next;
		}
	} else if (secondHelper != nullptr) {
		Node *h2 = secondHelper; //Pointer to head of second linked list
		while (h2 != nullptr) {
			//Append the end of second linked list
			Node *newNode = new Node; //Pointer to node of newly allocated memory
			newNode->letter = h2->letter;
			newNode->number = 0;
			newNode->next = nullptr;
			Node *mergeHelper = mergedHead;//Pointer to head of merged linked list
			while (mergeHelper->next != nullptr) {
				mergeHelper = mergeHelper->next;
			}
			mergeHelper->next = newNode;
			h2 = h2->next;
		}
	}
}

