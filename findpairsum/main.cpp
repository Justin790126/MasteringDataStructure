/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int A[] = {6,3,8,10,16,7,5,2,9,14};

int SA[] = {1,3,4,5,6,8,9,10,12,14};


int main()
{
    printf("========Find pair sum 1 (S)========\n");
    int k =10;
    for (int i = 0; i < 10; i++) {
        int e1 = A[i];
        for (int j = i+1; j < 10; j++) {
            if (A[j] + e1 == k) {
                printf("%d + %d = %d\n", e1, A[j], k);
            }
        }
    }
    printf("========Find pair sum 1 (E)========\n\n");
    
    printf("========Find pair sum by Hash (S)========\n");
    int* H = new int[17];
    for (int i = 0; i < 10; i++) {
        int resdual = k - A[i];
        if (resdual > 0) {
            if (H[resdual] > 0) {
                printf("%d + %d = %d \n", resdual, A[i], k);
            } else {
               H[A[i]]++; 
            }
        }
        
    }
    
    delete []H;
    
    printf("========Find pair sum by Hash (E)========\n\n");
    
    printf("========Find pair sum by two indexes in Sorting Array (S)========\n");
    int n = 10;
    int i = 0;
    int j = n-1;
    while (i<j) {
        if(SA[i] + SA[j] > k) {
            j--;
        } else if (SA[i] + SA[j] < k) {
            i++;
        } else if (SA[i] + SA[j] == k) {
            printf("%d + %d = %d \n", SA[i], SA[j], k);
            i++;
            j--;
        }
        
    }
    printf("========Find pair sum by two indexes in Sorting Array (E)========\n\n");
    return 0;
}