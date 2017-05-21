#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <cstring>
using namespace std;

int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

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
	cout << "Leak 2 test: A pointer points to one memory location and is then redirected" << endl;
	cout << "Expected output:" << endl;
	cout << "definitely lost: 8 bytes in 1 blocks" << endl;
	cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
	cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
	cout << "still reachable: 0 bytes in 0 blocks"<< endl;
	cout << "     suppressed: 0 bytes in 0 blocks" << endl;
	int start = getMilliCount();
	MemLeak m;
	m.createMemLeak("Foo Bar");
	m.createMemLeak("Foo Bar Foo Bar");
	int milliSecondsElapsed = getMilliSpan(start);
	cout << "Runtime: " <<  milliSecondsElapsed << endl; 
return 0;
}
