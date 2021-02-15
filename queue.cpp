// Joshua Carbajal
// queue.cpp
// 3/11/2019
// Purpose: Implementation file for the Queue class used to construct 
//				linked list queue. Has capabilites to add / remove values
//				from queue. Along with copy and assign new queues with 
//				identical values and delete these individual queues if needed.

#include "queue.h"
#include <assert.h>
using namespace std;
   
Queue::Queue() {
   front = nullptr;
   rear = nullptr;
   numItems = 0;
}

Queue::Queue(const Queue &obj) {
	numItems = 0;
	if (empty()) {
		Node *helper = obj.front;
		while (helper != nullptr) {
			enqueue(helper->value);
			helper = helper->next;
		}
	} else {
		front = nullptr;
		rear = nullptr;
	}
}

Queue& Queue::operator=(const Queue &obj) {
	if (this != &obj) {
		clear();
		numItems = 0;
		if (empty()) {
			Node *helper = obj.front;
			while (helper != nullptr) {
				enqueue(helper->value);
				helper = helper->next;
			}
		} else {
			front = nullptr;
			rear = nullptr;
		}	
	}
	return *this;
}
  
Queue::~Queue() {
   clear();
}
  
void Queue::enqueue(int num) {
   Node * newNode = new Node;
   newNode->value = num;
   newNode->next = nullptr;
   if (empty()) {
      front = newNode;
      rear = newNode;
   } else {
      rear->next = newNode;
      rear = newNode;
   }
   numItems++;
}
  
void Queue::dequeue() {
   assert(!empty());
   Node * temp = front;
   front = front->next;
   delete temp;
   numItems--;
}
  
int Queue::peek() const {
   assert(!empty());
   return front->value;
}
  
bool Queue::empty() const {
   return numItems == 0;
}
  
int Queue::size() const {
   return numItems;
}
 
void Queue::clear() {
   while (!empty())
   dequeue();
}

