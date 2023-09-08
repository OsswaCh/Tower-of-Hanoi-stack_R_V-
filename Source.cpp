#include <iostream>
#include <stdexcept> 
#include "Stackt.h"
using namespace std;



//rod1 is the starting rod
	//rod3 is the target 
	//rod2 is auxilary
	//size is the number of disks

int counter = 0;

template <class T>
void moveDisk(Stackt<T>& source, Stackt<T>& destination) {
	T disk = source.pop();
	destination.push(disk);
}

// Recursive Tower of Hanoi function
template <class T>
int towerOfHanoi(int size, Stackt<T>& source, Stackt<T>& destination, Stackt<T>& auxiliary) {
	
	

	if (size == 1) {
		moveDisk(source, destination);
		counter++;
	}
	else {
		
		towerOfHanoi(size - 1, source, auxiliary, destination);
		moveDisk(source, destination);
		counter++;
		towerOfHanoi(size - 1, auxiliary, destination, source);
	}
	return counter;
}


int main() {

	int size; 

	cout << "how many disks do you want to have?";
	cin >> size;

	Stackt<int> rod1(size);
	Stackt<int> rod2(size);
	Stackt<int> rod3(size);
	for (int i = 1; i < size + 1; i++)
		rod1.push(i);

	towerOfHanoi(size, rod1, rod3, rod2);
	cout<<"the number of moves is "<<counter<<endl;
	rod3.printStack();


	return 0;
}