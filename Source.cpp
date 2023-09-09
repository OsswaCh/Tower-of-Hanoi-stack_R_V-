#include <iostream>
#include <stdexcept> 
#include "Stackt.h"
using namespace std;

void convertSecondsToYearsDaysHours(long long seconds) {
	// Constants for conversion
	const long long secondsInMinute = 60;
	const long long secondsInHour = secondsInMinute * 60;
	const long long secondsInDay = secondsInHour * 24;
	const long long secondsInYear = secondsInDay * 365;

	// Calculate years, days, and hours
	long long years = seconds / secondsInYear;
	long long remainingSeconds = seconds % secondsInYear;
	long long days = remainingSeconds / secondsInDay;
	remainingSeconds %= secondsInDay;
	long long hours = remainingSeconds / secondsInHour;

	// Display the result
	std::cout << "Years: " << years << " Days: " << days << " Hours: " << hours << std::endl;
}


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

	int size; int choice;


	cout << "What do you want to play \n - Tower of Hanoi - (1) \t \t \t" << " - Tower of Brahma - (2) \n";
	cin >> choice;
	if (choice == 1) {
		cout << "how many disks do you want to have?";
		cin >> size;

		Stackt<int> rod1(size);
		Stackt<int> rod2(size);
		Stackt<int> rod3(size);
		for (int i = 1; i < size + 1; i++)
			rod1.push(i);


		towerOfHanoi(size, rod1, rod3, rod2);
		cout << "the number of moves is " << counter << endl;
		rod3.printStack();
	}
	else if (choice == 2) {
		Stackt<long long> rod1(64);
		Stackt<long long> rod2(64);
		Stackt<long long> rod3(64);
		for (long long i = 1; i < 65; i++)
			rod1.push(i);

		int moves = towerOfHanoi(64, rod1, rod3, rod2);
		cout << "The number of moves is " << moves << endl;
		convertSecondsToYearsDaysHours(towerOfHanoi(64, rod1, rod3, rod2));
		

		//when trying to perform this second choice, seemingly no result appears. However, it is not due to a non functional
		//code, but rather to the length of the operations at hand
		//in fact, (my laptop at least) only reaches 26 rods before taking a seemingly long while to give out the result 
		//and for that number of rods the counter (the number of seconds) is 67108863
		//equivalent to 2.128 years
	}
	else 
		throw std::invalid_argument("invalid choice");



	return 0;
}
