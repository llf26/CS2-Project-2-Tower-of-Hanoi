/*
Larry Fritz
CS2 Lianghu Tian
Project 2
*/

#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   //MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   //MyStack(const MyStack &);

   //operator= overloading
   //MyStack& operator=(const MyStack &);

   // Destructor






MyStack(int s)
{
stackArray = new T[s];
stackSize = s;
numElem = -1;
}

MyStack(const MyStack& obj)
{
  //Create array
  if(obj.stackSize > 0)
    stackArray = new T[obj.stackSize];
  else
    stackArray = nullptr;

  //Copy stackSize
  stackSize = obj.stackSize;

  //Copy the contents of the stack
  for(int i = 0; i < stackSize; i++)
    stackArray[i] = obj.stackArray[i];

  //Copy top of stack
  numElem = obj.numElem;
}



MyStack& operator=(const MyStack & obj)
{

 if(stackSize>0){
    delete [] stackArray;
 }
 //Copy stacksize
 this->stackSize = obj.stackSize;
stackArray = new T[stackSize];
 //Copy contents of stack
 for(int i = 0; i < obj.stackSize; i++)
    this->stackArray[i] = obj.stackArray[i];

 //Copy top of stack
 this->numElem = obj.numElem;
}

~MyStack()
{
    delete [] stackArray;
}

   // Stack operations
   //add an item to the stack by passing in a value
   void push(T num)
   {
       //If full don't do anything
       if(isFull())
       {
           std::cout << "The stack is full.\n";
       }

       else
       {
           //Stack is one larger
           numElem++;
           //Top of stack is set to value
           stackArray[numElem] = num;
       }
   }
   //pop a value out by returning the value
   T pop()
   {
       //If empty do nothing
       if(isEmpty())
       {
           std::cout << "The stack is empty.\n";
       }

       else
       {
           //Store top of stack
           T num = stackArray[numElem];
           //Remove top of stack
           numElem--;
           return num;
       }
   }
   //return the value at the top position in the stack
   T top()
   {
       return stackArray[numElem];
   }
   //tell if the stack is full
   bool isFull() const
   {
       bool status;
       //If the top is 1 less than the stack size
       if(numElem == stackSize - 1)
        status = true;
       else
        status = false;

       return status;
   }
   //tell if the stack is empty
   bool isEmpty() const
   {
       bool status;
      //If nothing is in the stack
       if(numElem == -1)
        status = true;
       else
        status = false;

       return status;
   }
   //tell how many items are in the stack
   int size() const
   {
       return numElem+1;
   }



};


#endif
