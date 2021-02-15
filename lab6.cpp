// Joshua Carbajal
// lab6.cpp
/* Purpose: Creates linked list of nodes. Populates linked list 
			with values read from file in ascending order.
			Prints the values to the user. Searches for integer duplicates
			and deletes them. Prints the list again without duplicates.
			Finally, deletes the entire linked list.
*/

#include <fstream>
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void addInOrder(Node *&head, int);
void printList(Node *head);
void removeDups(Node *&head);
void deleteList(Node *&head);

int main() {
	const string FILE = "/home/fac/ohsh/submit/19wq1230/files/lab6input.dat";
	int num;
	Node *head = nullptr;
	ifstream infile;
	infile.open(FILE);
	if (infile) {
		cout << "\nPrinting the list contents (read from file): \n";
		while (infile >> num) {
			cout << num << " ";
			addInOrder(*&head, num);
		}
	} else {
		cout << "Error opening the file. \n";
	}
	infile.close();
	cout << "\n";
	cout << "\nPrint the list contents (in order): \n";
	printList(head);
	cout << "\n";
	removeDups(*&head);
	cout <<"\nPrint the list contents (with duplicates removed): \n";
	printList(head);
	cout << "\n";
	deleteList(*&head);
}

void addInOrder(Node *&head, int num) {
	Node *prevNode;
	Node *helper;
	Node *newNode = new Node;
	newNode->data = num;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	} else {
		helper = head;
		prevNode = nullptr;
		while (helper != nullptr && helper->data < num) {
			prevNode = helper; 
			helper = helper->next; 
		}
		if (prevNode == nullptr) {
			head = newNode; 
			newNode->next = helper; 
		} else {
			prevNode->next = newNode; 
			newNode->next = helper; 
		}
	}
}

void printList(Node *head) {
	Node *helper = head;
	while (helper != nullptr) {
		cout << helper->data << " ";
		helper = helper->next;
	}
}

void removeDups(Node *&head) {
	Node *currNode = head;
	Node *prevNode;
	// Traversing the list, checking that both the current node and 
	// previous node are not at the end of the list
	while (currNode != nullptr && currNode->next != nullptr) {
		prevNode = currNode;
		currNode = currNode->next;
		cout << "Start, What they are pointing to \n";
		cout << "prevNode: " << prevNode->data << " ";
		cout << "currNode: " << currNode->data << "\n";
		cout << "\n";
		//Checks to see if data for both are the same
		while (prevNode->data == currNode->data) {
			cout << "These match \n";
			prevNode->next = currNode->next;
			delete currNode;
			currNode = prevNode->next;
			cout << "\nEnd, What they are pointing to \n";
			cout << "prevNode: " << prevNode->data << " ";
			cout << "currNode: " << currNode->data << "\n";
		}
		cout << "\n";
		printList(head); //To see whats happening to the list after each iteration
		cout << "\n";
	}
}

void removeDups(Node *&h) {
  Node *ptr = h;
  node *delPtr = nullptr;
  while (ptr != nullptr && ptr->next != nullptr) {
    while (ptr->next != nullptr && ptr->data == ptr->next->data) {// != nullptr gets rid of segmentation fault
      delPtr = ptr->next;
      ptr->next = delPtr->next;
      delete delPtr;
    }
    ptr = ptr->next;
  }
}
  
void deleteList(Node *&head) {
	Node *helper;
	while (head != nullptr) {
		helper = head;
		head = head->next;
		delete helper;
	}
}
	
	
	
	
