/* Write a program to know if two linked lists intersect or not and return the intersecting point*/
/*APPROACH:
    1. Run through each LL to find lengths and tails.
    2. Campare the tails (by ref) if they are same they are intersecting.
    3. set two pointers at the start.
    4  move apart pointers by the diff of their lengths.
    5. When pointers meet that is the point of intersection.  */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
int size(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

Node *intersectPoint(Node *head1, Node *head2)
{

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    if (ptr1 == NULL || ptr2 == NULL)
    {

        return NULL;
    }
    int a = size(ptr1);
    int b = size(ptr2);

    int d = abs(a - b);
    if (a > b)
    {
        for (int i = 0; i < d; i++)
        {
            ptr1 = ptr1->next;
        }
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

void print(Node *node)
{
    if (node == NULL)
        cout << "NULL";
    while (node->next != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << node->data;
}
int main()
{
    /*
	Create two linked lists

	1st Linked list is 3->6->9->15->30
	2nd Linked list is 10->15->30

	15 30 are elements in the intersection list
	*/

    Node *newNode;
    Node *head1 = new Node();
    head1->data = 10;
    Node *head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    Node *intersect_node = NULL;

    // Find the intersection node of two linked lists
    intersect_node = intersectPoint(head1, head2);

    cout << "INTERSECTINGPOINT LIST :";

    print(intersect_node);

    return 0;
}
