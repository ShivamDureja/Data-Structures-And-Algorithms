                            
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    
    void solve(TreeNode* root){
        if(root == NULL)return;
        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;

        if(child > root->val) root->val = child;
        else{
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }
        solve(root->left);
        solve(root->right);

        int total = 0;
        if(root->left) total += root->left->val;
        if(root->right) total += root->right->val;
        if(root->left or root->right) root->val = total;
    }

    void changeTree(TreeNode* root) {
        solve(root);
    }
};


void inordertraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inordertraversal(root->left);
    cout << root->val << " ";
    inordertraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    cout << "Binary Tree before modification: ";
    inordertraversal(root);
    cout << endl;

    sol.changeTree(root);

    cout << "Binary Tree after Children Sum Property: " ;
    inordertraversal(root);
    cout << endl;

    return 0;
}
                            
                        