/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node* next;
}* first = NULL, *last=NULL, *second=NULL, *third =NULL;


void create(int A[], int n)
{
    int i;
    Node* t, *cur;
    first = (Node*)malloc(sizeof(Node));
    first->data = A[0];
    first->next = NULL;
    
    cur = first;
    
    for(i=1; i < n; i++)
    {
        t = (Node*)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        cur->next = t;
        cur = t;
    }
}


void create2(int A[], int n)
{
    int i;
    Node* t, *cur;
    second = (Node*)malloc(sizeof(Node));
    second->data = A[0];
    second->next = NULL;
    
    cur = second;
    
    for(i=1; i < n; i++)
    {
        t = (Node*)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        cur->next = t;
        cur = t;
    }
}

int count(Node* p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}


int Rcount(Node* p)
{
    if (p == NULL) return 0;
    else {
        return Rcount(p->next)+1;
    }
}

int sum(Node* p)
{
    int sum = 0;
    while (p != NULL) 
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(Node* p)
{
    if (p == NULL) return 0;
    else {
        return p->data +Rsum(p->next);
    }
}

void Display(Node* p)
{
    while (p != NULL) 
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RDisplay(Node* p)
{
    if (p) {
        cout << "first: " << p->data << endl;
        RDisplay(p->next);
        cout << "last: " << p->data << endl;
    }
}

int max(Node* p)
{
    int max = 0;
    while (p!=NULL)
    {
        max = p->data > max ? p->data : max;
        p = p->next;
    }
    return max;
}

int Rmax(Node* p)
{
    int x = 0;
    if (p == NULL) return 0;
    
    x = Rmax(p->next);
    return p->data > x ? p->data : x;
}

Node* LSearch(Node* p, int key)
{
    while(p!=NULL) {
        if (p->data == key) return p;
        p = p->next;
    }
    return NULL;
}

Node* RLSearch(Node* p, int key)
{
    if (p==NULL) return NULL;
    
    if (p->data == key) return p;
    return RLSearch(p->next, key);
}

Node* MLSearch(Node*p, int key)
{
    Node* q;
    while(p != NULL)
    {
        if (p->data == key) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return q;
}


void InsertLast(int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        last = first = t;
    } else {
        last->next = t;
        last = t;
    }
}

void Insert(Node* p, int index, int x)
{
    if(index < 0 || index > count(p)) return;
    
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    
    if (index == 0) {
        t->next = first;
        first =t;
    } else {
        int i = 0;
        for (i = 0; i < index-1; i++) {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(Node* p, int x)
{
    Node* t, *q;
    t = new Node;
    t->data =x;
    t->next = NULL;
    if (first == NULL) {
        first = t;
        
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p==first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}


int Delete(Node*p, int index)
{
    Node* q;
    int x = -1;
    
    if (index <1 || index > count(p)) return x;
    
    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(Node* p)
{
   int x = -65536;
   while(p!=NULL) {
       
       if (p->data < x) return 0;
       x = p->data;
       p =p->next;
   }
   return 1;
}

void RemoveDuplicate(Node* p)
{
    Node* q = p->next;
    
    while(q!= NULL)
    {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(Node* p)
{
    int* A = (int*)malloc(sizeof(int)*count(p));
    Node* q=p;
    int i = 0;
    while(q!=NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    
    while (q!=NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }
    free(A);
}

void Reverse2(Node* p)
{
    Node* q,*r;
    q = NULL;
    r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(Node*q, Node* p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

void Concate(Node*p, Node*q)
{
    third = p;
    while(p->next!=NULL) {
        p = p->next;
    }
    p->next = q;
}

void Merge(Node* p, Node* q)
{
    Node* last;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    
    while(p!=NULL && q!=NULL)
    {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (q!= NULL) last->next = q;
    else last->next = p;
}



int isLoop(Node* f)
{
    Node*p,*q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;
    } while(p && q && p!=q);
    return p==q ? 1 : 0;
}

int findMiddle(Node* p)
{
    Node* q = p;
    while(q)
    {
        q=q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    return p->data;
}



struct PolynomoidNode
{
    int coeff;
    int power;
    PolynomoidNode* next;
}* poly;

double Eval(PolynomoidNode* p, int x)
{
    double sum = 0.0;
    while(p != NULL)
    {
        sum += p->coeff * pow(x, p->power);
        p = p->next;
    }
    return sum;
}

void createPoly()
{
    PolynomoidNode* t, *last;
    
    int num;
    printf("Enter number of terms ");
    scanf("%d", &num);
    
    printf("Enter each term with coeff and power \n");
    for (int i = 0; i < num; i++) {
        
        t = new PolynomoidNode;
        scanf("%d%d", &t->coeff, &t->power);
        t->next = NULL;
        if (poly == NULL) {
            poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
        
    }
}

void DisplayPoly(PolynomoidNode* p)
{
    while(p)
    {
        cout << p->coeff << "x^ " << p->power << " +";
        p = p->next;
    }
    cout << "0" << endl;
}

int main()
{
    Node* t1,*t2;
    int A[] = {8,6,3,9,10,4,2,12};

    
    create(A, 8);
    
    cout << "middle = " << findMiddle(first) << endl;
    
    
    createPoly();
    DisplayPoly(poly);
    cout << "sum = " << Eval(poly, 1) << endl;
    return 0;
}







