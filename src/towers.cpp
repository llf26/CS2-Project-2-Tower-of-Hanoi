/*
Larry Fritz
CS2 Lianghu Tian
Project 2
*/
#include <iostream>
#include "towers.h"
#include "mystack.h"
#include <math.h>

using namespace std;
Towers::Towers(int num)
{
    //Set pointers to dynamic stacks
    peg1 = new MyStack<int>(num);
    peg2 = new MyStack<int>(num);
    peg3 = new MyStack<int>(num);
    numDisk = num;

    //Place n pegs on peg 1
    for(int i = num; i >=1; i--)
    peg1->push(i);

}

Towers::~Towers()
{
    //Delete pointers
    delete peg1;
    delete peg2;
    delete peg3;
}

Towers::Towers(const Towers & obj)
{
    //Set pointers to new stacks of obj size
    peg1 = new MyStack<int>(obj.numDisk);
    peg2 = new MyStack<int>(obj.numDisk);
    peg3 = new MyStack<int>(obj.numDisk);

    //Copy contents of each peg
    for(int i =0; i < obj.numDisk; i++)
    {
        peg1[i] = obj.peg1[i];
    }

    for(int i =0; i < obj.numDisk; i++)
    {
        peg2[i] = obj.peg2[i];
    }

    for(int i =0; i < obj.numDisk; i++)
    {
        peg3[i] = obj.peg3[i];
    }
    //Copy number of disks from obj
    numDisk = obj.numDisk;
}

Towers& Towers::operator=(const Towers & obj)
{
    //Copy contents of stack from right side to left side
    for(int i =0; i < obj.numDisk; i++)
    {
        this->peg1[i] = obj.peg1[i];
    }

    for(int i =0; i < obj.numDisk; i++)
    {
        this->peg2[i] = obj.peg2[i];
    }

    for(int i =0; i < obj.numDisk; i++)
    {
        this->peg3[i] = obj.peg3[i];
    }
    //Copy numDisk from right side to left side
    this->numDisk = obj.numDisk;
}



//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}

void Towers::setDisks()
{
    //Put N disks on peg1 going from smallest to largest top to bottom
    for(int i = numDisk; i >=1; i--)
    peg1->push(i);

    this->plotPegs();
}

void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)
{
    //Pop from source into destination
    d->push(s->pop());
    plotPegs();
}

void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
 plotPegs();
   //Calculate moves
   int moves = pow(2,numDisk) -1;

   //Implement given Tower of Hanoi solution algorithm for even number of disks
   if(numDisk % 2 == 0)
   {
       //While not finished moving disks
       while(!(s->isEmpty() && (t->isEmpty())))
       {
           //Decide legal move for disk
           if(s->top() < t->top())
           //Move disk
           moveOne(s, t);
           else
           //Move disk
           moveOne(t,s);
           //Decide legal move
           if(s->top() < d->top())
           //Move disk
           moveOne(s, d);
           else
           //Move disk
           moveOne(d,s);
           //Decide legal move
           if(t->top() < d->top())
           //Move disk
           moveOne(t,d);

           else
            //Move disk
           moveOne(d,t);
       }

   }

   else
   {
     //Implement algorithm for odd number of disks (same instructions with different order)
     while(!(d->isFull()))
       {
           if(s->top() < d->top() && !(d->isFull()))
           moveOne(s, d);
           else
           if(!(d->isFull()))
              moveOne(d,s);

           if((s->top() < t->top()))
           moveOne(s, t);
           else
           if(!(d->isFull()))
           moveOne(t,s);

           if(t->top() < d->top())
           moveOne(t,d);

           else
            if(!(d->isFull()))
           moveOne(d,t);
       }
   }




}
