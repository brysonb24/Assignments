#include <iostream>
#include "myVector.h"
#include <string>

using namespace std;

int main() {

	//Declares a vector size 10
	myVector V(10);

	//Prints if vector is empty
	if (!V.popBack()) 
	{
		cout << "There is nothing in vector.." << endl;
	}
	//Adds three variables to vector
	V.pushBack(13);
	V.pushBack(31);
	V.pushBack(73);

	//Prints vector
	V.print();

	//Adds 10000 variables to vector
	for (int j = 0; j < 10000; j++)
	{
		V.pushBack(j % 7);
	}
	//Prints size of vector
	cout << V.vSize << endl;

	//Removes 9998 variables from vector
	for (int j = 0; j < 9998; j++)
		V.popBack();

	//Prints size of vector
	cout << V.vSize << endl;

	//Pushes string into vector
	V.pushBack("Blah");

	system("pause");
	return 0;
}