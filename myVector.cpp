#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

/**
*   Creates an instance of the  myVector class
*
*   @param {int} size : The initial size of the vector
*/

myVector::myVector(int size)
{
	oSize = size;
	vSize = size;
	theVector = new int[vSize];
	index = 0;
}

/**
*   Adds a variable to the end of the vector and increases the
*   size of the vector if it is full
*
*   @param {int} item : The variable to be added
*/

void myVector::pushBack(int item)
{
	// checks whether vector is full, and if so increases size by
	// a factor of 1.5
	if (index == vSize)
	{
		tempV = new int[(double)vSize * 1.5];
		for (int i = 0; i < vSize; i++)
		{
			tempV[i] = theVector[i];
		}
		vSize = vSize + ((double)vSize / 2);
		tempP = theVector;
		theVector = tempV;
		delete tempP;
	}
	// puts variable onto end of vector
	theVector[index] = item;

	// increments index marker of vector
	index++;

}

int myVector::popBack()
{
	//Checks if vector is empty or not
	if (index != 0)
	{
		int Val = theVector[index - 1];

		index--;

		vectSize = (double)index / (double)vSize;

		if (vectSize <= .4)
		{
			if ((vSize / 2) > oSize)
			{
				tempV = new int[vSize / 2];
				vSize /= 2;
			}
			else
			{
				tempV = new int[oSize];
				vSize = oSize;
			}
			for (int i = 0; i < index; i++)
			{
				tempV[i] = theVector[i];
			}
			tempP = theVector;
			theVector = tempV;
			delete tempP;
		}
		//Returns last variable
		return Val;
	}
	else
	{
		//Return if empty
		return false;
	}
}

//Prints variables into vector.
void myVector::print()
{
	for (int i = 0; i < index; i++)
	{
		cout << theVector[i] << " ";
	}
	cout << endl;
}

/**
*   @param {string} nogo : The string attempting to be pushed
*/
void myVector::pushBack(string nogo)
{
	cout << "Vector is not for strings" << endl;
	return;
}