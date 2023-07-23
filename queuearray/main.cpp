/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int* Q;
};

void create(Queue* q, int size)
{
    q->size=size;
    q->front = q->rear = -1;
    q->Q = new int[size];
    
    
}

void enqueue(Queue* q, int x)
{
    if(q->rear == q->size-1) {
        cout << "Queue is full" << endl;
    }
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(Queue* q)
{
    int x = -1;
    if (q->front ==q->rear) {
        cout << "Queue is empty" << endl;
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(Queue q)
{
    for (int i = q.front+1; i <= q.rear ; i++) {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    create(&q, 5);
    
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    
    Display(q);
    

    return 0;
}

