
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <chrono>
#include <string.h>

using namespace std;

void createLeak()
{
	static char *memptr = NULL;
	memptr = new char [100];
}

int main(){
        cout << "Leak 13 test, a static local variable is allocated to a block of memory and the reallocated before deallocation of the original block" << endl;
        cout << "Expected output:" << endl;
        cout << "definitely lost: 100  bytes in 1 blocks" << endl;
        cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
        cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
        cout << "still reachable: 100 bytes in 1 blocks"<< endl;
        cout << "     suppressed: 0 bytes in 0 blocks" << endl;

        auto start = chrono::high_resolution_clock::now();
        createLeak();
	createLeak();
        auto finish = chrono::high_resolution_clock::now();
        cout << "Runtime: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << "ns" << endl;

        return 0;
}
