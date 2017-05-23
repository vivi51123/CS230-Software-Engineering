#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
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


void createLeak()
{
        char **memptrarr; 
        memptrarr = new char *[2];
        memptrarr[0] = new char [100];
        memptrarr[1] = new char [24];
        if (memptrarr[0] != NULL)
        {
                cout << "memptr is not Null" << endl;
        }else{
                cout << "memptr is Null" << endl;
        }
        memptrarr++;
        memptrarr[0]++;
        delete [] memptrarr; 
        delete [] memptrarr[0];
}
 
int main(){
        cout << "Leak 8 test: Type 8 - Testing internal pointer to pointer memory allocation" << endl;
        cout << "Expected output:" << endl;
        cout << "definitely lost: 8 bytes in 1 blocks" << endl;
        cout << "indirectly lost: 124 bytes in 2 blocks" << endl;
        cout << "  possibly lost: 0 bytes in 0 blocks" << endl;
        cout << "still reachable: 0 bytes in 0 blocks"<< endl;
        cout << "     suppressed: 0 bytes in 0 blocks" << endl;
        int start = getMilliCount();
        createLeak();
        int milliSecondsElapsed = getMilliSpan(start);
        cout << "Runtime: " <<  milliSecondsElapsed << endl; 
return 0;
}