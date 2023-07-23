/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>


int A[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12 };

int B[] = { 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17 };

int C[] = { 6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19 };

int D[] = { 3, 7, 4, 9, 12, 6, 1, 11, 2, 10 };

using namespace std;

int
main ()
{

  int sum;
  int n = 12;
  for (int i = 0; i < n; i++) {
    sum += A[i];
  }

  int sum_real = 12 * (1 + 12) / 2;
  int missing_element = sum_real - sum;
  printf ("missing_element by method 1 = %d\n===================\n",
	  missing_element);


  n = 11;
  int diff = B[0] - 0;
  for (int i = 0; i < n; i++) {
    if ((B[i] - i) != diff) {
	  missing_element = i + diff;
	  break;
	}
  }

  printf ("missing_element by method 2 = %d\n===================\n",
	  missing_element);


  printf ("Find Missing multiple elements by diff: \n");
  n = 11;
  diff = C[0] - 0;
  for (int i = 0; i < n; i++) {
    if ((C[i] - i) != diff) {
	  while (diff < (C[i] - i)) {
	    printf ("%d\n", i + diff);
	    diff++;
	  }
	}
  }
  printf ("===================\n");
  
  int max = 0;
  for (int i = 0; i < 10; i++) {
      if (D[i] > max) max = D[i];
  }
  
  int* H = (int*)malloc(sizeof(int) * max);
  for (int i = 0; i < 10; i++) {
      H[D[i]]++;
  }
  
  printf ("Find Missing multiple elements by hash table method: \n");
  for (int i = 0; i < max; i++) {
    if (H[i] == 0 && i != 0) {
        printf("%d\n", i);
    }
  }
  
  free(H);
   printf ("===================\n");
  
  
  
  return 0;
}
