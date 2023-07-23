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
} *top = NULL;

int isEmpty()
{
    return top ? 0 :1;
}

int isFull()
{
    Node* t = new Node;
    int full = t ? 1 : 0;
    delete t;
    return full;
}

void push(int x)
{
    Node* t = new Node;
    if (!t) {
        cout << "Stack overflow" << endl;
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop()
{
    Node* p = top;
    int x = -1;
    if (!top) {
        cout << "Stack empty" << endl;
        return x;
    }
    x = p->data;
    top = top->next;
    delete p;
    return x;
}

void Display()
{
    Node* p = top;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int peek(int index)
{
    int x  = -1;
    if (!top) {
        cout << "Stack empty" << endl;
        return x;
    }
    Node* p = top;
    for (int i = 0; i < index-1; i++) {
        p = p->next;
    }
   x = p->data;
   return x;
}

int stackTop()
{
    return top->data;
}

int main()
{
    Node* top = new Node;
    push(10);
    push(20);
    push(30);
    cout << peek(1) << endl;
    
    Display();
    return 0;
}