/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
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

int isOperand(char x)
{
    if (x=='+' || x=='-' || x=='*' || x=='/') {
        return 0;
    }
    return 1;
}

int pre(char x)
{
    if (x=='+' || x=='-') {
        return 1;
    } else if(x=='*' || x=='/') {
        return 2;
    }
    return 0;
}


char* InToPost(char* infix)
{
    char* postfix;
    int len = strlen(infix);
    postfix = new char(len+1);
    int i = 0,j = 0;
    while(infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (pre(infix[i]) > pre(top->data)) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while (top!=NULL) {
       postfix[j++] = pop();
    }
    postfix[j] = '\0';
    
    return postfix;
}

int main()
{
    char* infix = "a+b*c-d/e";
    push('#');
    
    char* postfix = InToPost(infix);
    cout << std::string(postfix) << endl;
 
    return 0;
}