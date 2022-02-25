#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two lists in sorting order
Node *mergelists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    // if some elements left in ll
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    { // base case
        return root;
    }
    root->next = flatten(root->next); // rec call

    root = mergelists(root, root->next); // merge

    return root;
}

int main()
{

    return 0;
}
