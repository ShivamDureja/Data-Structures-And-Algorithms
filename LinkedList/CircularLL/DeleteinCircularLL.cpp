#include <iostream> //Deleting and Displaying elemnt from circular Linked list!
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

int length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;

    }while(p!=head);
    return len;
}

int Delete(int pos)
{

    Node *p, *q;
    int x;
    if(pos<0 || pos>length(head)){
        return -1;
    }
    if (pos == 1)
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }

        x = head->data;
        if (p == head)
        {
            delete head;
            head = NULL;
        }else{
        p->next = head->next;
        delete head;
        head = p->next;
    }}
    else
    {
        p = head;
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next=q->next;
        x = q->data;
        delete q;
    }
    return x;
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
    cout<<"Enter the position to be deleted";
    int pos;
    cin>>pos;
    cout<<"Deleted element is "<<Delete(pos)<<endl;
    cout<<"Final linked list"<<endl;
    Display(head);
    return 0;
}