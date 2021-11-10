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
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev = last;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while(p){
        cout<<p->data<<endl;
        p=p->next;
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
    cout<<"Linked list is =>"<<endl;
    display(first);
    return 0;
}