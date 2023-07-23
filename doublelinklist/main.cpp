/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct Node
{
    Node* prev;
    int data;
    Node* next;
} *first = NULL;

void create(int A[], int n)
{
    Node*t,*last;
    int i = 0;
    
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // tedious
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node* p)
{
    while (p!= NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(Node* p)
{
    int len = 0;
    while(p != NULL) {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(Node*p, int index, int x)
{
    Node* t, *q;
    if (index < 0 || index > Length(p)) return;
    
    
    if (index == 0) {
        t = new Node;
        t->data = x;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
        
    } else {
        t = new Node;
        t->data = x;
        
        q = new Node;
        p = first;
        for (int i = 0; i < index-1; i++) {
            p = p->next;
        }
        q = p->next;
        
        p->next = t;
        t->prev = p;
        t->next = q ? q : NULL;
        
        if (q) {
          q->prev = t;
        }
        
        
    }
}

int Delete(Node*p, int index)
{
    int x = -1;
    if (index < 1 || index > Length(p)) return x;
   
    if (index == 1) {
        x = first->data;
        first = first->next;
        if (first) first->prev = NULL;
        delete p;
    } else {
        for (int i = 0; i < index-1; i++) {
            p = p->next;
        }
        x = p->data;
        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        delete p;
    }
    return x;
}

void Reverse(Node* p)
{
    while (p!= NULL)
    {
        Node* temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL) first = p;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 5);
    Reverse(first);
    Display(first);

    return 0;
}