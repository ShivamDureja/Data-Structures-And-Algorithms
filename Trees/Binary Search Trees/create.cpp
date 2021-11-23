#include <iostream>             //BINARY SEARCH TREES
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)            //Inserting and creating BST
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void InOrder(struct Node *p)   //Traversing tree to produce sorted elements
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << endl;
        InOrder(p->rchild);
    }
}

struct Node *Search(int key)
{                               //Searching in BST

    struct Node *p = root;

    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        else if (key > p->data)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    return NULL;
}

int main()
{
    struct Node *temp;
    int x;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    cout << "Final BST is ->" << endl;
    InOrder(root);
    cout << "Which element u want to search??" << endl;
    cin >> x;
    temp = Search(x);
    if (temp != NULL)
    {
        cout << "Element found!!" << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }

    return 0;
}