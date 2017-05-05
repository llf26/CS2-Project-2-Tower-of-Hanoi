/*
Larry Fritz
CS2 Lianghu Tian
Project 2
*/
#ifndef TOWERS_H
#define TOWERS_H

#include "MyStack.h"

//********************************//
//prototype of class tower        //
//put all functions to towers.cpp //
//DO NOT MODIFY THIS FILE         //
//********************************//

class Towers {
	private:
		MyStack<int> *peg1; //start stack
		MyStack<int> *peg2; //tmp stack
		MyStack<int> *peg3; //destination stack
		int numDisk;	//number of discs to move
	public:
		//constructor, passing in an int to tell how many discs to move
		Towers(int);

		//destructor
		~Towers();

		//copy constructor
		Towers(const Towers &);

	   //operator= overloading
	   Towers& operator=(const Towers &);

	   //start function, DO NOT MODIFY
		void start() {
			move(numDisk, peg1, peg2, peg3);
		}

		//void plot(){this->plotPegs();}

		//void testmoveone(){moveOne(peg1, peg2);}

		//void testmove(){move(1, peg1, peg2, peg3);}



	private:
		void setDisks();	//initialize start-tower by putting discs in, then print out the status of three towers after initialized
		void plotPegs();	//print out the status of three towers
		void move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d); //move n discs from tower s to tower d by using a temporary tower t
		void moveOne(MyStack<int>* s, MyStack<int>* d);  //move one discs from tower s to tower d
};
#endif
