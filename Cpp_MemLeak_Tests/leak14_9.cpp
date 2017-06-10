#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <chrono>
#include <string.h>

using namespace std;

class train
{
public:
	train();
	~train();
};

train::train()
{
}

train::~train()
{
	cout << "Train destructor called" << endl;
}

class steamTrain : public train
{
public:
	steamTrain();
	~steamTrain();
	void addFuel(int quantity);

private:
	int *fuel;
};

steamTrain::steamTrain()
{
	cout << "allocating 1 steamtrain" << endl;
	fuel = new int[1];
}

steamTrain::~steamTrain()
{
	delete [] fuel;
}

class electricTrain : public train
{
public:
	electricTrain();
	~electricTrain();
	void powerOn();

private:
	int  *power;
};

electricTrain::electricTrain()
{
	cout << "allocating 1 electricTrain" << endl;
	power = new int[1];
}

electricTrain::~electricTrain()
{
	delete [] power;
}

void electricTrain::powerOn()
{
	if (power != NULL)
	{
		delete [] power;
	}
	power = new int[10];
}

int main(){
        cout << "Leak 14 test, a base class pointer is assigned to a derived class, the base class destructor is then called instead of the derived class destructor" << endl;
        cout << "Expected output:" << endl;
        cout << "definitely lost: 100  bytes in 1 blocks" << endl;
        cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
        cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
        cout << "still reachable: 100 bytes in 1 blocks"<< endl;
        cout << "     suppressed: 0 bytes in 0 blocks" << endl;

        auto start = chrono::high_resolution_clock::now();
        train	*steam = new steamTrain();
	train	*electric = new electricTrain();
	delete steam;
	delete electric;
        auto finish = chrono::high_resolution_clock::now();
        cout << "Runtime: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << "ns" << endl;

        return 0;
}

