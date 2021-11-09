#include <iostream> //Inserting Node in existing Linked List at a given position
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

void Display(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << endl;
        p = p->next;
    };
};

void Insert(int pos, int value)
{
    Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    

    if (pos == 0)
    {
        
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
            if (p)
            {

                t->next = p->next;
                p->next = t;
            };
        };
    };
};

int main()
{
    int A[50], n;
    cout << "Enter size of linked list" << endl;
    cin >> n;
    cout << "Enter elements of linked lists" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    cout << "Here is ur Linked list" << endl;
    Display(first);
    cout << "Enter the position where u want to insert!!" << endl;
    int pos, value;
    cin >> pos;
    cout << "Enter the value" << endl;
    cin >> value;
    Insert(pos, value);
    cout << "Final Linked list" << endl;
    Display(first);

    return 0;
}