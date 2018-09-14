#include <iostream>
#include <string>

using namespace std;

class myVector {
private:
	int *theVector;
	int *tempV;
	int *tempP;
	int oSize;
	int index;
	double vectSize;
public:
	myVector(int size);
	int popBack();
	int vSize;
	void print();
	void pushBack(string nogo);
	void pushBack(int item);
};
