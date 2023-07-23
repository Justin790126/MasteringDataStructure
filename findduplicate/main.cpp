/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int A[] = {3,6,8,8,10,12,15,15,15,20};

int B[] = {8,3,6,4,6,5,6,8,2,7};

int B2[] = {8,3,6,4,6,5,6,8,2,7};

int main()
{
    printf("============find duplicate 1 (S)============\n");
    int n = 10;
    int last_duplicate = 0;
    for (int i = 0; i < n-1; i++) {
        if (A[i+1] == A[i] && A[i+1] != last_duplicate) {
            last_duplicate = A[i];
            printf("%d \n", last_duplicate);
        }
    }
    printf("============find duplicate 1 (E)============\n");

    printf("============count duplicate 1 (S)============\n");
    int j = 0;
    for (int i = 0; i < n-1; i++) {
        if (A[i+1] == A[i]) {
           
            j = i+1;
            while(A[j] == A[i]) j++;
            printf("%d is appearing %d times\n", A[i], j-i);
            i = j -1;
            
        }
    }
    printf("============count duplicate 1 (E)============\n\n");
    
    printf("============count duplicate by Hash table (S)============\n");
    
    int* H = (int*)malloc(sizeof(int) * 20);
    for (int i = 0; i < n; i++) {
        H[A[i]]++;
    }
    
    for (int i = 0; i <= 20; i++) {
        if (H[i] > 1) {
            printf("%d is appearing %d times\n", i, H[i]);
        }
    }
    free(H);
    
    printf("============count duplicate by Hash table (E)============\n\n");
    
    printf("============count duplicate 2 (S)============\n");
    for (int i = 0; i < n; i++) {
        int count = 1;
        int ele = B[i];
        if (ele != -1) {
            for (int j = i+1; j < n; j++) {
                if (B[j] == ele) {
                    count++;
                    B[j] = -1;
                }
            }
            if (count > 1) {
                cout << ele << " is appearing " << count << " times "<< endl;
            }
        }

    }
    printf("============count duplicate 2 (E)============\n");
    
    printf("============count duplicate by Hash table 2 (S)============\n");
    int* H2 = new int[8];
    
    for (int i = 0; i < n; i++) {
        H2[B2[i]]++;
    }
    
    for (int i = 0; i <= 8; i++) {
        if (H2[i] > 1) {
            printf("%d is appearing %d times\n", i, H2[i]);
        }
    }
    
    delete []H2;
    
    printf("============count duplicate by Hash table 2 (E)============\n\n");
    return 0;
}
