#include <iostream> //Creating and Displaying Circular Linked List
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * head;

void create(int A[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

void RecDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << endl;
        RecDisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int A[50], n;
    cout << "Enter size of linked list";
    cin >> n;
    cout << "Enter elements of linked lists";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    cout << "Circular Linked List is =>" << endl;
    Display(head);
    cout << "Circular Linked List is(from recursion) =>" << endl;
    RecDisplay(head);
    return 0;
}