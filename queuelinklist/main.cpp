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
}* front=NULL, *rear=NULL;

void enqueue(int x)
{
    Node* t = new Node;
    if (!t) {
        cout << "Queue is Full" << endl;
    } else {
        t->data = x;
        t->next = NULL;
        if (front==NULL) {
            front = rear = t;
        } else {
            rear->next =t;
            rear = t;
        }
        
    }
}

int dequeue()
{
    int x = -1;
    Node* t = NULL;
    if (front == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Display()
{
    Node* p = front;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    Display();
    return 0;
    
}