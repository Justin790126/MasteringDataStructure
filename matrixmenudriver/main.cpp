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
    int* A;
    int i, j, n, ch, x;
    
    printf("Enter dimension ");
    scanf("%d", &n);
    
    //A = (int*)malloc(sizeof(int) * n);
    //A = new int[n];
    A = new int[n*(n+1)/2];
    
    do
    {
      switch(ch)
      {
        case 1: {
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &A[i-1]);
            }
            break;
        }
        case 2: {
            printf("Enter index ");
            scanf("%d%d", &i, &j);
            //if(i==j) printf("%d ", A[i-1]);
            if(i>=j) printf("%d ", A[i*(i-1)/2+j-1]);
            else printf("0 ");
            break;
        }
        case 3: {
            printf("Enter row, col and element ");
            scanf("%d%d%d", &i, &j, &x);
            //if (i==j) A[i-1] = x;
            if (i>=j) A[i*(i-1)/2+j-1] = x;
            
            break;
        }
        case 4: {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    //if (i==j) printf("%d ", A[i-1]);
                    if (i>=j) printf("%d ", A[i*(i-1)/2+j-1]);
                    else printf("0 ");
                }
            }
            break;
        }
          
          
      }
    } while (true);
    
    //free(A);
    delete A;
    return 0;
}