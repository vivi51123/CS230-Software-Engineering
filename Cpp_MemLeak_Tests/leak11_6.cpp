#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <chrono>
#include <string.h>

using namespace std;

class Leak
{
public:
    static void createLeak(char *p_name);
    static char *name;
};

void Leak::createLeak(char	*p_name)
{
    size_t	len;
    len = strlen(p_name);
    name = new char [len + 1];
    if (name != NULL)
    {
        strcpy(name, p_name);
    }
}

char * Leak::name = NULL;

int main(){
	cout << "Leak 11 test, a static class variable is allocated to a block of memory and then reallocated before deallocation of the original block" << endl;
	cout << "Expected output:" << endl;
	cout << "definitely lost: 18  bytes in 2 blocks" << endl;
	cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
	cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
	cout << "still reachable: 40 bytes in 1 blocks"<< endl;
	cout << "     suppressed: 0 bytes in 0 blocks" << endl;

	auto start = chrono::high_resolution_clock::now();
	Leak L;
	L.createLeak("This is leak one ");
	L.createLeak("This is anther leak after the first one");
	auto finish = chrono::high_resolution_clock::now();
	cout << "Runtime: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << "ns" << endl;
	
	return 0;
}

