/* Given a circular ll, implement algo that returns node present at beginning of loop*/
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node*next;
};

Node * newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Display(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head =  head->next;
    }
    cout<<endl;
}

Node * detectLoop(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node * slowPtr = head;
    Node * fastPtr = head;
    Node * entryPtr = head;

    while(fastPtr->next && fastPtr->next->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr){                // Loop is detected
            while(slowPtr != entryPtr){   // found the entry location
                slowPtr = slowPtr->next;
                entryPtr = entryPtr->next;
            }return entryPtr;
        }
    }return NULL;
}


int main(){
    Node *head = newNode(50);
    head->next = newNode(25);
    head->next->next = newNode(10);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(11);

    head->next->next->next->next->next = head->next->next;   //creating a loop
    Node * temp = detectLoop(head);
    if(temp == NULL){
        cout<<"Loop does not exist"<<endl;
    }else{
        cout<<"Loop staring node is   "<<temp->data<<endl;
    }
    return 0;
}