#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflows";
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack Underflows";
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
    {
        cout << "Position Invalid!!";
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

void Display(stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << endl;
    }
}

int main()
{

    struct stack st;
    cout << "Enter size of stack";
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    peek(st, 2);

    Display(st);

    return 0;
}