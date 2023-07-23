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
    char data;
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

void push(char x)
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
    char x = -1;
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



int isBalance(char* str)
{
   for (int i = 0; i < str[i]!='\0'; i++) {
       if (str[i]=='(') push(str[i]);
       else if (str[i]==')') {
           if (isEmpty()) return 0;
           
           pop();
       }
   }
   
    
 
    return isEmpty() ? 1 : 0;
}

int main()
{
    char* str = "((a+b)*(c-d))";
    cout << isBalance(str) << endl;
    return 0;
}