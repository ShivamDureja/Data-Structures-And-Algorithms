#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void printLeft(Node* root){
    if(root == nullptr){
        return ;
    }
    if(root->left){
        cout<<root->data<<" ";
        printLeft(root->left);
    }else if(root->right){
        cout<<root->data<<" ";
        printLeft(root->right);
    }
}

void printRight(Node* root){
    if(root == nullptr){
        return;
    }
    if(root->right){
        printRight(root->right);
        cout<<root->data<<" ";
    }else if(root->left){
        printRight(root->left);
        cout<<root->data<<" ";
    }
}

void printLeaves(Node* root){
    if(root == nullptr){
        return;                           //inOrder TraversaL
    }
    printLeaves(root->left);
    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}
void printBoundary(Node* root){
    if(root == nullptr){
        return ;
    }
    if(root->left){
        cout<<root->data<<" ";
        printLeft(root->left);
    }else if(root->right){
        cout<<root->data<<" ";
        printRight(root->right);
    }
}



int main(){
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    printBoundary(root);
    return 0;
}