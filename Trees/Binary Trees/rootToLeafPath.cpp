#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:  
        int data;
        Node* left;
        Node* right;
  public:
    Node(int x) : data(x),left(nullptr),right(nullptr) {}
};

class Solution{
    public :
        bool solve(Node* node, vector<int> &ans, int target){
             if(node == nullptr)return false;
            ans.push_back(node->data);
            if(node->data == target){
                return true;
            }
            if (solve(node->left, ans, target)
            || solve(node->right, ans, target)) {
            return true;
        }
            ans.pop_back();
            return false;
        }
        
        vector<int> getPath(Node* root, int target){
            vector<int> ans;
            solve(root,ans,target);
            return ans;
        }
};

int main(){
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;
    int target = 7;
    vector<int> path = sol.getPath(root,target);

    
    for(int num : path){
        cout<<endl;
        cout<<"path - "<<num<<endl;
    }
    return 0;
}