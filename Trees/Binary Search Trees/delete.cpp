#include <iostream> //BINARY SEARCH TREES
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key) //Inserting and creating BST
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

void InOrder(struct Node *p) //Traversing tree to produce sorted elements
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << endl;
        InOrder(p->rchild);
    }
}

struct Node *RInsert(struct Node *p, int key)
{ //Recursive Insertion

    struct Node *t = p;
    if (t == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)

        p->lchild = RInsert(p->lchild, key);

    else if (key > p->data)

        p->rchild = RInsert(p->rchild, key);

    return p;
}

int main()
{

    root = RInsert(root, 50);
    RInsert(root, 15);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);
    cout << "Final BST is ->" << endl;
    InOrder(root);

    return 0;
}