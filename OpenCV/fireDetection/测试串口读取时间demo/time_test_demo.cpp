#include <iostream>
#include <ctime>

#ifdef _WIN32 
#include <Windows.h> 
#else 
#include <unistd.h> 
#endif

using namespace std;

int main(int argumentCount, const char* argumentValues[]) 
{
    clock_t t1,t2,t3; 
    while(1){
        t1 = clock();     
        cout << "time: " <<  1.0*t1/CLOCKS_PER_SEC << " s" << endl;
        Sleep(1000);
    }
}
