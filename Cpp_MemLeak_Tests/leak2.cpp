#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <cstring>
#include <chrono>
using namespace std;

class MemLeak
{
public:
	MemLeak();

	~MemLeak();

	void createMemLeak(char	*p_memptr);

private:
	char	*memptr;
};

MemLeak::MemLeak()
{
	memptr = NULL;
}

MemLeak::~MemLeak()
{
	if (memptr != NULL)
		delete [] memptr;
}

void MemLeak::createMemLeak(char	*p_memptr)
{
	/*if (memptr != NULL)
	{
		delete [] memptr;
		memptr = NULL;
	}*/

	size_t	len;

	len = strlen(p_memptr);
	memptr = new char [len + 1];
	if (memptr != NULL)
	{
		strcpy(memptr, p_memptr);
	}
}


 
int main(){
	cout << "Leak 2 test: A pointer is assigned to one memory location and is then redirected without releasing the memory block. The second memory block is deleted" << endl;
	cout << "Expected output:" << endl;
	cout << "definitely lost: 8 bytes in 1 blocks" << endl;
	cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
	cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
	cout << "still reachable: 0 bytes in 0 blocks"<< endl;
	cout << "     suppressed: 0 bytes in 0 blocks" << endl;
	
	auto start = chrono::high_resolution_clock::now();
	MemLeak m;
	m.createMemLeak("Foo Bar");
	m.createMemLeak("Foo Bar Foo Bar");
	auto finish = chrono::high_resolution_clock::now();
	cout << "Runtime: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << "ns" << endl;
	return 0;
}

