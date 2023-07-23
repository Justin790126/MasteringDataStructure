/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;


struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    Term* terms;
};

void create(Poly* p)
{
    printf("Number of terms ? ");
    scanf("%d", &p->n);
    p->terms = (Term*)malloc(sizeof(Term) * p->n);
    
    printf("Enter terms\n");
    int i;
    for (i = 0; i < p->n; i++) {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
    
}


void display(Poly p)
{
    int i;
    for (i = 0; i < p.n; i++) {
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if(p.terms[i].exp != 0) {
            printf("+");
        }
    }
    printf("\n");
}


Poly* add(Poly* p1, Poly* p2)
{
    Poly* sum;
    sum = (Poly*)malloc(sizeof(Poly));
    
    sum->terms = (Term*)malloc(sizeof(Term) * (p1->n + p2->n));
    
    int i,j,k;
    i=j=k=0;
    
    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp > p2->terms[j].exp)
        {
            sum->terms[k++] = p1->terms[i++];
        } else if(p1->terms[i].exp < p2->terms[j].exp) {
            sum->terms[k++] = p1->terms[j++];
        } else {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
        
        
    }
    
    for(;i<p1->n;i++) sum->terms[k++] = p1->terms[i];
    for(;j<p2->n;j++) sum->terms[k++] = p2->terms[j];
    
    sum->n = k;
    return sum;
}

int main()
{
    Poly p1, p2, *p3;
    create(&p1);
    create(&p2);
    
    p3 = add(&p1, &p2);
    
    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    return 0;
}
