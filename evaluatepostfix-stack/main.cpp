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
} *top = NULL, *st = NULL;

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
    if (x=='+' || x=='-' || x=='*' || x=='/'|| x=='^'|| x=='('|| x==')') {
        return 0;
    }
    return 1;
}

int preOut(char x)
{
    int pre = -1;
    switch (x)
    {
        case '+':
        case '-': {
            pre = 1;
            break;
        }
        case '*':
        case '/': {
            pre = 3;
            break;
        }
        case '^': {
            pre = 6;
            break;
        }
        case '(': {
            pre = 7;
            break;
        }
        case ')': {
            pre = 0;
            break;
        }
        default: break;
    }
    return pre;
}


int preIn(char x)
{
    int pre = 0;
    switch (x)
    {
        case '+':
        case '-': {
            pre = 2;
            break;
        }
        case '*':
        case '/': {
            pre = 4;
            break;
        }
        case '^': {
            pre = 5;
            break;
        }
        case '(': {
            pre = 0;
            break;
        }
        case ')': {
            pre = -1;
            break;
        }
        default: break;
    }
    return pre;
}

int Eval(char* postfix)
{
    int len = strlen(postfix);
    int x1,x2, r;
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            push(postfix[i]-'0');
        } else {
            
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
                case '+': {
                    r=x1+x2;
                    push(r);
                    break;
                }
                case '-': {
                    r=x1-x2   ;
                    push(r);
                    break;
                }
                case '*': {
                    r=x1*x2;
                    push(r);
                    break;
                }
                case '/': {
                    r=x1/x2;
                    push(r);
                    break;
                }
            }
        }
    }
    while (top) {
        r = pop();
    }
    return r;
}

int main()
{
    char* postfix = "35*62/+4-";
    //Eval(infix);
    cout << Eval(postfix) << endl;


 
    return 0;
}