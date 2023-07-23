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
    int data;
    Node* next;
}* Head;

void create(int A[], int n)
{
    int i;
    Node* t,*last;

#if 0
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
#endif
    Head = new Node;
    Head->data = A[0];
    Head->next = NULL;
    last = Head;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = Head;
}

void Display(Node* h)
{
    do {
        cout << h->data << " ";
        h = h->next;
    } while(h!=Head);

    cout << endl;
}

void RDisplay(Node* h)
{
    static int flag = 0;
    if (h!=Head || flag == 0) {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(Node* p)
{
    int len = 0;
    
    do {
        len++;
        p = p->next;
    } while(p!=Head);
    return len;

#if 0
    while (p->next != Head) {
        len++;
        p = p->next;
    }
    return len+1;
#endif
}

void Insert(Node* p, int index, int x)
{
    Node* t;
    int i = 0;
    if (index < 0 || index > Length(p)) return;
    if (index == 0) {
        t = new Node;
        t->data = x;
        
        if (!Head) {
            Head = t;
            Head->next = Head;
        } else {
            
            while(p->next != Head) {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
        
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
        
    }
}


int Delete(Node* p, int index)
{
    Node* q;
    int x = -1;
    if (index < 0 || index > Length(Head)) return -1;
    
    if (index == 1) {
        p = Head;
        while(p->next != Head) p = p->next;
        p->next = Head->next;
        
        if (p==Head) {
            delete Head;
            Head = NULL;
        } else {
           x = Head->data;
           delete Head;
           Head = p->next;
        }
        
    } else {
        p = Head;
        for (int i = 0; i < index-2; i++) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    cout << "Delete value = " << Delete(Head , 8) << endl;
    RDisplay(Head);

    return 0;
}



