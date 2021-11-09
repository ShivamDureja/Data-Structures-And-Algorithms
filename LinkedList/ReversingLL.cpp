#include <iostream>  //Reversing Linked List using sliding pointers!
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
    }
}

void Reverse(struct Node *l){
    Node *p,*q,*r;
    p=first;
    q=NULL;
    r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
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
    cout << "Linked List is =>" << endl;
    Display(first);
    Reverse(first);
    cout<<"After reverse!!";
    Display(first);

    return 0;
}