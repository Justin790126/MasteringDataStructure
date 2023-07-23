/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    char A[] = "finding";
    long int H = 0;
    
    
    for (int i = 0; A[i] != '\0'; i++) {
        int shift = A[i] - (int)'a';
        int x = 1 << shift;
        if (H & x) {
            cout << A[i] << " duplicate" << endl; 
        } else {
            H  = H | x;
        }
    }

    return 0;
}