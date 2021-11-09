#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

Node *Search(Node *p, int key)
{
    Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int A[50];
    int n;
    struct Node *temp;
    cout << "Enter size =>";
    cin >> n;
    cout << "Enter elements of linked list" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    int key;
    cout << "Enter the element u want to search" << endl;
    cin >> key;
    temp = Search(first, key);
    if (temp!=NULL)
    {
        cout << "Key is found" << temp->data << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    };

    return 0;
}