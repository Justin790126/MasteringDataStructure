/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char toLower(char a)
{
    if (a >= (int)'A' && a <= (int)'Z') {
        // cvt to lower case
        return (char)((int)a + 32);
    } else {
        return a;
    }
}

int main()
{
    char A[]="wElcome";
    
    cout << "============Upper/Lower case conversion(S)============" << endl;

    for (int i = 0; i < strlen(A); i++) {
        if (A[i] >= (int)'a' && A[i] <= (int)'z') {
            // cvt to upper case
            A[i] = (char)((int)A[i] - 32);
        } else if (A[i] >= (int)'A' && A[i] <= (int)'Z') {
            // cvt to lower case
            A[i] = (char)((int)A[i] + 32);
        } else {
            A[i] = A[i];
        }
    }
    
    cout << A << endl;
    cout << "============Upper/Lower case conversion(E)============" << endl;
    
    
    cout << "============Count vowels (S)============" << endl;
    char B[] = "How are you";
    int vcount = 0;
    for (int i = 0; i < strlen(B); i++) {
        switch ((int)toLower(B[i]))
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': {
            vcount++;
            break;
        }
    }
    cout << "number of vowels = " << vcount <<endl;
    cout << "============Count vowels (E)============" << endl;
    
    cout << "============Number of words (S)============" << endl;
    int wordcount = 1;
    for (int i = 0; i < strlen(B); i++) {
        if (B[i] == ' ' && B[i-1] != ' ') {
            wordcount++;
        }
    }
    cout << "number of words = " << wordcount <<endl;
    cout << "============Number of words (E)============" << endl;
    
    cout << "============Find duplicates in a string (S)============" << endl;

    cout << " 2: Hash table method " << endl;
    char B3[] = "finding";
    int size_of_hash = (int)('z'-'a');
    char* H = new char[size_of_hash];
    for (int i = 0; B3[i] != '\0'; i++) {
        H[(int)(B3[i]-'a')]++;
    }
    
    for (int i = 0; i < size_of_hash; i++) {
        if (H[i] > 1) cout << char(i + (int)'a') << " appear " << (int)H[i] << " times"<< endl;
    }
    delete H;
    cout << "============Find duplicates in a string (E)============" << endl;
    
    return 0;
}
