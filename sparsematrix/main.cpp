/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    Element* e;
};

void create(Sparse* s)
{
    printf("Enter dimension ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter number of non-zero ");
    scanf("%d", &s->num);
    s->e = new Element[s->num];
    
    printf("Enter all elements \n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            
            if (i==s.e[k].i && j == s.e[k].j) {
                cout << s.e[k++].x << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

Sparse* add(Sparse* s1, Sparse* s2)
{
    Sparse* sum;
    int i = 0, j = 0, k = 0;
    sum = (Sparse*)malloc(sizeof(Sparse));
    sum->e = (Element*)malloc((s1->num + s2->num) * sizeof(Element));
    
    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i) {
            sum->e[k++] = s1->e[i++];
        } else if (s1->e[i].i > s2->e[j].i) {
            sum->e[k++] = s2->e[j++];
        } else {
            if (s1->e[i].j < s2->e[j].j) {
                sum->e[k++] = s1->e[i++];
            } else if (s1->e[i].j > s2->e[j].j) {
                sum->e[k++] = s2->e[j++];
            } else {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    
    for(;i<s1->num;i++) sum->e[k++] = s1->e[i];
    for(;j<s2->num;j++) sum->e[k++] = s2->e[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    
    return sum;
    
}

int main()
{
    Sparse s1,s2,*s3;
    
    create(&s1);
    create(&s2);
    
    s3 = add(&s1, &s2);
    
    printf("First matrix \n");
    display(s1);
    printf("Second matrix \n");
    display(s2);
    
    printf("Sum matrix \n");
    display(*s3);
    
    

    return 0;
}

