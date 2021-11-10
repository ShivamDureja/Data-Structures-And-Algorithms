#include <iostream> //Inserting Node in existing Linked List at a given position
using namespace std;
typedef struct Node *nodeptr;
struct Node
{
    int data;
    struct Node *next;
};

void create(int A[], int n, nodeptr *head)
{
    // struct Node *t, *last;
    nodeptr newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = A[0];
    newnode->next = nullptr;
    *head = newnode;
    nodeptr temp = *head;
    // last = first;
    for (int i = 1; i < n; i++)
    {
        nodeptr newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = A[i];
        newnode->next = nullptr;
        temp->next = newnode;
        temp = temp->next;
        // last->next = t;
        // last = t;
    }
}

void Display(nodeptr head)
{
    nodeptr temp = head;
    while (temp->next)
    {
        cout << temp->data << endl;
        temp = temp->next;
    };
};

void Insert(int pos, int value, nodeptr *head)
{
    // Node *t, *p;
    nodeptr newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    int i = 1;
    nodeptr temp = *head;
    if (pos == 0)
    {
        *head = newnode;
        newnode->next = temp->next;
        // t->next = first;
        // first = t;
    }
    else if (pos > 0)
    {
        // p = first;
        // for (int i = 0; i < pos  && p; i++)
        while (i <= pos - 1 && temp->next)
        {
            if (temp)
            {
                temp = temp->next;
            }
            else
            {
                cout << "out of bounds \n";
                exit(0);
            }
            i++;
        };
        if (temp != nullptr)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    };
};

int main()
{
    nodeptr head = nullptr;
    int A[50], n;
    cout << "Enter size of linked list" << endl;
    cin >> n;
    cout << "Enter elements of linked lists" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n, &head);
    cout << "Here is ur Linked list" << endl;
    Display(head);
    cout << "Enter the position where u want to insert!!" << endl;
    int pos, value;
    cin >> pos;
    cout << "Enter the value" << endl;
    cin >> value;
    Insert(pos, value, &head);
    cout << "Final Linked list" << endl;
    Display(head);

    return 0;
}
