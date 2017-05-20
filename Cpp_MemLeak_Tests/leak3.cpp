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

class memObj
{
public:
	memObj();

	~memObj();

private:
	char	*data;
};

memObj::memObj()
{
	data = new char [1000];
}

memObj::~memObj()
{
	delete [] data;
}
 
int main(){
	cout << "Leak 2 test" << endl;
	int start = getMilliCount();

	memObj	*array;

	array = new memObj[10] memObj();

	//delete array;
	delete [] array;

	int milliSecondsElapsed = getMilliSpan(start);
	cout << "Runtime: " <<  milliSecondsElapsed << endl; 
return 0;
}
