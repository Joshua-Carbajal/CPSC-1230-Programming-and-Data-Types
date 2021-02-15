// Joshua Carbajal
// queue.h
// 3/11/2019
// Purpose: Specification file for the Queue class used to construct 
//				linked list queue. Has capabilites to add / remove values
//				from queue. Along with copy and assign new queues with 
//				identical values and delete these individual queues if needed.


#ifndef QUEUE_H    
#define QUEUE_H    
 
class Queue {
	public:
		Queue();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Front and Rear assigned nullptr, numItems assigned 0
		
		Queue(const Queue &);
		// Copy constructor
		// pre(conditions): Linked list must be empty
		// post(conditions): Allocates linked list with identical values 
		//							from the previous linked list
		
		Queue& operator=(const Queue &);
		// Copies and assigns a linked list
		// pre(conditions): Addresses must not be equal
		// post(conditions): Deletes linked list, dynamically allocates and 
		//							populates new linked list
		
		~Queue(); 
		// Deletes linked list queue
		// pre(conditions): Linked list not empty
		// post(conditions): Linked list is deallocated
		
		void enqueue(int);
		// Appends value to end of queue
		// pre(conditions): None
		// post(conditions): Appends nodes to linked list, numItems incremented
		
		void dequeue();
		// Removes value from head of queue
		// pre(conditions): Linked list is not empty
		// post(conditions): Deletes linked list, numItems decremented
		
		int peek() const; // could be changed to front()
		// Returns first value of queue
		// pre(conditions): None
		// post(conditions): Returns front value of linked list
		
		bool empty() const;
		// Returns if queue is empty
		// pre(conditions): None
		// post(conditions): Returns true if number of items is assigned 0
		
		int size() const;
		// Returns size of queue
		// pre(conditions): None
		// post(conditions): Returns number of items
		
	private:
		struct Node {
		int value;
		Node *next;
		};
		Node *front; // Head of queue
		Node *rear; // Tail of queue
		int numItems; // Number of elements in queue
		void clear(); // Resets the queue to zero values
};

#endif