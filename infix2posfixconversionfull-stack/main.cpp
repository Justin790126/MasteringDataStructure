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
            if (preOut(infix[i]) > preIn(top->data)) {
                push(infix[i++]);
            } else {
                if (preOut(infix[i]) < preIn(top->data)) {
                   
                    postfix[j++] = pop();
                } else if (preOut(infix[i])  == preIn(top->data)) {
        
                    if (top->data == '(') pop();
                    i++;
                }
                
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
    char* infix = "((a+b)*c)-d^e^f";
    push('#');
    
    char* postfix = InToPost(infix);
    cout << std::string(postfix) << endl;

 
    return 0;
}