#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct Node *p,int pos, int value)
{
    struct Node *t;
    if (pos < 0 || pos > length(first))
    {
        return ;
    }
    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main()
{
    int n;
    int A[50];
    cout << "enter size of linked list";
    cin >> n;
    cout << "enter elements for linked lists" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    cout << "Linked list is =>" << endl;
    display(first);
    cout << "Enter the position where node to be inserted ";
    int pos;
    cin >> pos;
    int value;
    cout << "enter the value of node ";
    cin >> value;
    insert(first,pos, value);
    cout << "Here is final doubly linked list=>" << endl;
    display(first);
    return 0;
}