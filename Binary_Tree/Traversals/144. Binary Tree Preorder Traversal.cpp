/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]
*/

class Solution {
    public:
    vector<int>ans;
    void preorder_traversal(TreeNode* root){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder_traversal(root);
        return ans;
    }
};