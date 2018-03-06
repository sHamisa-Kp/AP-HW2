/*FullName: Shamisa Kaspour
  StudentNum: 9423087*/

class Queue {
private:
	int Qmemory; // memory of Q
	double* Qelmnt; // present elements of Q
	int end; // end point
	int start; // start point
	bool emptyFlag; // true when Q is empty

public:
	/* Constructor */
	Queue(std::string fileName);
	~Queue();
	
	void displayQueue();
	void enQueue(double num);
	double deQueue();

};