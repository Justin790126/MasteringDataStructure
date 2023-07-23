/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;


struct Matrix
{
    int* A;
    int n;
};


void Set(Matrix* m, int i, int j, int x)
{
    if (i>=j) m->A[(m->n*(j-1) + (j-2)*(j-1)/2+i-j)] = x;
    
    // col major: (m->n*(j-1) + (j-2)*(j-1)/2+i-j)
    // row major: (i*(i-1)/2+j-1)
}

int Get(Matrix* m, int i, int j)
{
    if (i>=j) return m->A[(m->n*(j-1) + (j-2)*(j-1)/2+i-j)];
    return 0;
}
void Display(Matrix* m)
{
    for (int i = 1; i <= m->n; i++) {
        for (int j = 1; j <= m->n; j++) {
            if (i>=j) {
                cout << m->A[(m->n*(j-1) + (j-2)*(j-1)/2+i-j)] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}


int main()
{
    Matrix m;
    int i,j,x;
    printf("Enter dimension ");
    scanf("%d", &m.n);
    
    m.A = (int*)malloc(m.n*(m.n+1)/2*sizeof(int));
    
    printf("Enter all elements\n");
    for (i=1;i<=m.n;i++) {
        for(j=1;j<=m.n;j++) {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n");
    Display(&m);

    return 0;
}