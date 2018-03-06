/*FullName: Shamisa Kaspour
  StudentNum: 9423087*/

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include"Queue.h"

/* constructor definition */
Queue::Queue(std::string fileName) {
	std::fstream inFile; // file
	std::string word2; // word2 have value of elements
	std::string str; // store each element
	start = 0;
	end = 0;
	emptyFlag = true; 
	inFile.open(fileName);
	if(!inFile)
		std::cout << "Unable to open inFile" << std::endl;
	else {
		size_t i{0};
		inFile >> Qmemory; 
		Qelmnt = new double[Qmemory];
		inFile >> word2;
		for(char c : word2) {
			/* separate each element */
			if(c != ',')
				str += c;
			else {
				emptyFlag = false; // Q is NOT empty
				Qelmnt[i] = atof(str.c_str()); 
				i++;
				str.erase(0);
			}
		}
		Qelmnt[i] = atof(str.c_str());
		start = 0;
		end = i;
	}
}
/* destructor definition */
Queue::~Queue() {
	delete[] Qelmnt; // delete dynamic array
}

/* function to insert elements in Circular Queue */
void Queue::enQueue(double num) {
	if(start - end == 1 || (end == Qmemory - 1 && start == 0)) 
		std::cout << "Unable to store this variable!" << std::endl;

	else {
		if(emptyFlag)
			Qelmnt[start] = num;
		/* end of array */
		else if(end == Qmemory - 1) {
			Qelmnt[0] = num;
			end = 0;
		}
		else
			Qelmnt[++end] = num;
		emptyFlag = false;
	}

}

/* function to display elements present in Circular Queue */
void Queue::displayQueue() {
	if(emptyFlag)
		return;
	int point{start};
	while(end != point) {
		std::cout << Qelmnt[point++] << " ";
		/* end of array */
		if(point == Qmemory) {
			point = 0;
		}
	}
	std::cout << Qelmnt[end];
	std::cout << std::endl;
}

/* function to delete elements present in Circular Queue */
double Queue::deQueue() {
	int startCopy{start};
	if(emptyFlag) {
		std::cout << "Unable to delete this variable!" << std::endl;
		return -1;
	}
	else if(start == end)
		emptyFlag = true; // NOW Q is empty
	else
	{
		start++;
		if(start == Qmemory)
			start = 0;
	}

	return Qelmnt[startCopy]; // return deleted value
}