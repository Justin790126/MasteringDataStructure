/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int* s;
};

void create(Stack* st)
{
    printf("ENter size of stack ");
    scanf("%d", &st->size);
    st->s = new int[st->size];
    st->top = -1;
}

void Display(Stack st)
{
    for (int i = st.top; i >=0; i--) {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

void push(Stack* st, int x)
{
    if (st->top == st->size -1) {
        // full
        cout << "Stack overflow" << endl;
    } else {
        
        st->s[++st->top] = x;
    }
}

int pop(Stack* st)
{
    int x = -1;
    if (st->top == -1) {
        cout << "stack underflow" << endl;
        return x;
    }
    x = st->s[st->top--];
    return x;
}

int peek(Stack st, int index)
{
   int x = -1;
   if (st.top-index+1 < 0) {
       cout << "invalid position" << endl;
       return x;
   }
   x = st.s[st.top-index+1];
   return x;
}

int isEmpty(Stack st)
{
    return (st.top == -1);
}

int isFull(Stack st)
{
    return (st.top == st.size-1);
}

int stackTop(Stack st)
{
    if (st.top == -1) return -1;
    return st.s[st.top];
}

int main()
{
    Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    cout << peek(st, 1) << endl;

    Display(st);
    
    return 0;
}
