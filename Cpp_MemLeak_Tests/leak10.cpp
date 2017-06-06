#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <chrono>

using namespace std;

//can change these scores here to throw an exception or not, if exception is thrown memleak occurs
int winnerScore = 2;
int loserScore = 3;

void createLeak()
{
	int *memptr;
	memptr = new int[2];
	try { 
	    if(winnerScore <= loserScore) {
		throw 99;
	    }
	}
	catch(int x) {
	    cout << "Winner score <= Loser score.  ERROR: " << x << endl;
	    return;
	}
	memptr[0] = winnerScore;
	memptr[1] = loserScore;
	//do whatever you want here
	delete [] memptr; 
}
 
int main(){
	cout << "Leak 1 test, memory is allocated and not released before the program ends" << endl;
	cout << "Expected output:" << endl;
	cout << "definitely lost: 8 bytes in 1 blocks" << endl;
	cout << "indirectly lost: 0 bytes in 0 blocks" << endl;
	cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
	cout << "still reachable: 0 bytes in 0 blocks"<< endl;
	cout << "     suppressed: 0 bytes in 0 blocks" << endl;

	auto start = chrono::high_resolution_clock::now();
	createLeak();
	auto finish = chrono::high_resolution_clock::now();
	cout << "Runtime: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << "ns" << endl;
	
	return 0;
}

