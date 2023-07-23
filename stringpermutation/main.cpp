/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void perm1(char S[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i = 0;
    if (S[k] == '\0') {
        if (Res[k] == '\0') {
            cout << Res << endl;
        }
        
    } else {
        for (i = 0; S[i] != '\0'; i++) {
            if (A[i] == 0) {
                Res[k] = S[i];
                A[i] = 1;
                perm1(S, k+1);
                A[i] = 0;
            }
        }
    }

}


void perm2(char S[], int l, int h)
{
    int i;
    if (l==h) {
        cout << S << endl;
    } else {
        for (i = l; i <= h; i++) {
            std::swap(S[l], S[i]);
            perm2(S, l+1, h);
            std::swap(S[l], S[i]);
        }
    }
}

int main()
{
    char S[] = "ABC";
    
    perm2(S, 0, 2);

    return 0;
}