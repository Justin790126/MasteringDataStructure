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
} *Head = NULL;

void create(int A[], int n)
{
    Node*t,*last;
    int i = 0;
    
    Head = new Node;
    Head->data = A[0];
    Head->prev = Head->next = NULL;
    last = Head;
    
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // tedious
        t->prev = last;
        last->next = t;
        last = t;
    }
    last->next = Head;
    Head->prev = last;
}

void Display(Node* p)
{
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p!=Head);
    
    cout << endl;
}

int Length(Node* p)
{
    int len = 0;
    do {
        len++;
        p = p->next;
    } while(p!=Head);
    return len;
}

void Insert(Node*p, int index, int x)
{
    Node* t, *q;
    if (index < 0 || index > Length(p)) return;
    
    
    if (index == 0) {
        t = new Node;
        t->data = x;
        t->next = Head;
        t->prev = Head->prev;
        Head->prev->next = t;
        
    } else {
        t = new Node;
        t->data = x;
        
        q = new Node;
        p = Head;
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
        x = Head->data;
        Head->next->prev = Head->prev;
        Head->prev->next =  Head->next;
        Head = Head->next;
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
        if (p != NULL && p->next == NULL) Head = p;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 5);
    Delete(Head, 1);
    Display(Head);

    return 0;
}