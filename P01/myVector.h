#include <iostream>

using namespace std;

/****************************
* *
* Class *
* Implementation *
* *
* *
****************************/
class myVector {
	//Private variables
private:
	int *theVector;
	int vSize;
	int minSize;
	int index;

	//Private methods 
	double percentFull();
	void growArr();
	void shrinkArr();
public:
	//Constructors
	myVector();
	myVector(int size);

	//Public Methods
	void print();
	int pop_back();
	void push_back(int val);
	int size();
};
