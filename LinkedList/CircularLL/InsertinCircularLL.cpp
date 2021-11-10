#include <iostream>             //Creating and Displaying Circular Linked List
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

void Insert(int pos, int value)
{

    Node *p, *t;
    if(pos<0 || pos>length(head)){   //checking if position is valid or not!
        return;
    }
    if (pos == 0)                   //inserting at beginning or end
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        if (head == NULL)
        {                           //If linked list contains single element (only head)
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
        }
    }else{                          //inserting in between linked list Nodes!
        p=head;
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=value;
        t->next=p->next;
        p->next=t;

    }
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
    cout << "Enter value to be inserted";
    int value;
    cin >> value;
    cout << "Enter position of node to be inserted";
    int pos;
    cin >> pos;
    Insert(pos, value);
    cout << "Final Linked list =>" << endl;
    Display(head);

    return 0;
}