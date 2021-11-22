#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    struct Node **S;
};


void StackCreate(struct Stack *st,int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node * ));
}

void push(Stack *st, struct Node * x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflows";
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node  *pop(Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        cout << "Stack Underflows";
    }
    else
    {
        x = st->S[st->top--];
       
    }
    return x;
}

int isEmptyStack(struct Stack st){
    if(st.top == -1 )
        return 1;
    return 0;
}

int isFullStack(struct Stack st){
    return st.top == st.size-1;
}

