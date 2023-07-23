/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int size;
        int* Q;
    public:
        Queue() {
            front = rear = -1;
            size = 10;
            Q = new int[size];
        }
        Queue(int size) {
            front = rear = -1;
            this->size = size;
            Q = new int[this->size];
        }
        
        void enqueue(int x);
        void enqueueFront(int x);
        int dequeue();
        int dequeueRear();
        void Display();
};

void Queue::enqueue(int x)
{
    if (rear == size-1) {
        cout << "Queue is full" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

void Queue::enqueueFront(int x)
{
    if (front == -1) {
        cout << "Queue is overflow" << endl;
    } else {
        
        Q[front] = x;
        front--;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear) {
        cout << "Queue is empty" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

int Queue::dequeueRear()
{
    int x = -1;
    if (rear == -1) {
        cout << "Queue is underflow" << endl;
    } else {
       x = Q[rear];
        rear--; 
    }
    return x;
}

void Queue::Display()
{
    for (int i = front+1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();

    return 0;
}
