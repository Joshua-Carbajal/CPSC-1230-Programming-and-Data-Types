// Joshua Carbajal
// stack.h
// 3/11/2019
// Purpose: Specification file for the Stack class used to create a stack, 
//				populate the stack and remove from the stack. Has the capabilities
//				to copy, assign and delete the stack.

#ifndef STACK_H
#define STACK_H

class Stack {
	public:
		Stack(int);
		// Default constructor
		// pre(conditions): None
		// post(conditions): Dyncamically allocaed new array, assigns capacity 
		//									 to value and top to -1
		
		~Stack();
		// Deletes the dynamically allocated array
		// pre(conditions): None
		// post(conditions): Deletes dynamically allocated memory of array
		
		Stack(const Stack &); 
		// Copies the dynamically allocated array
		// pre(conditions): None
		// post(conditions): Copies value of array to newly allocated array
		
		Stack& operator=(const Stack &);
		// Copies and assigns a dynamically allocated array
		// pre(conditions): Addresses must not be equal
		// post(conditions): Deletes array, creates new array and populates
		//							with values from previous array.
		
		void push(int);
		// Appends value to end of the stack
		// pre(conditions): top + 1 must be equal to capacity
		// post(conditions): Appends new value to array
		
		void pop();
		// Removes value from end of the stack
		// pre(conditions): Array is not empty
		// post(conditions): Decrements top
		
		int peek() const;
		// Returns top of the stack
		// pre(conditions): Array is not empty
		// post(conditions): Returns top of the array
		 
		bool empty() const;
		// Returns true if stack is empty
		// pre(conditions): None
		// post(conditions): Returns true if array is empty
		
		int size() const;
		// Returns size of the stack
		// pre(conditions): None
		// post(conditions): Returns top of array + 1
		
	private:
	  int *arr; // Dynamically allocated array
	  int capacity; // Size of array
	  int top; // Assigned to last value in array
	  void resize(); // Increases capacity of array
};

 #endif
