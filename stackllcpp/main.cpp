/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class Stack
{
    private:
        Node* top;
    
    public:
        Stack() {
            top = NULL;
        }
        ~Stack() {
            
        }
        void push(int x);
        int pop();
        void Display();
};

void Stack::push(int x)
{
    Node* t = new Node;
    if (!t) {
        cout << "Stack is full" << endl;
        return;
    }
    
    t->data = x;
    t->next = NULL;
    t->next = top;
    top = t;
    
    
}

int Stack::pop()
{
    int x = -1;
    if (!top) {
        cout << "Stack is empty" << endl;
        return x;
    }
    Node* p = top;
    x = p->data;
    top = top->next;
    delete p;
    return x;
}

void Stack::Display()
{
    Node* p = top;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    stk.Display();

    return 0;
}