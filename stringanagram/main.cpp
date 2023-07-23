/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    char A[]="decimal";
    char B[]="medical";
    
    int n = (int)('z'-'a');
    
    int* H = new int[n];
    
    for (int i = 0; A[i] != '\0'; i++) {
        int idx = A[i] - 'a';
        H[idx]++;
    }
    
    bool is_anagram = true;
    for (int i = 0; B[i] != '\0'; i++) {
        int idx = B[i] - 'a';
        H[idx]--;
        if (H[idx] < 0) {
            is_anagram = false;
            break;
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        if (H[i] != 0) {
            is_anagram = false;
            break;
        }
    }
    
    cout << "is_anagram = " << is_anagram << endl;
    
    
    delete []H;

    return 0;
}

