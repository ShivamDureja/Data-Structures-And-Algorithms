#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* newNode(int data);

TreeNode* createMinimalBST(int arr[],int start,int end){
    if(start>end)
        return NULL;
    int mid = (start+end)/2;

    TreeNode* root = newNode(arr[mid]);

    root->left = createMinimalBST(arr,start,mid-1);
    root->right = createMinimalBST(arr,mid+1,end);
    return root;
}

TreeNode* newNode(int data){
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(TreeNode* node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}





int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
     TreeNode *root = createMinimalBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    return 0;
}