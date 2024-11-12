/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]
*/

class Solution {
    void inorder_traversal(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return ;
        }
        inorder_traversal(root->left,ans);
        ans.push_back(root->val);
        inorder_traversal(root->right,ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder_traversal(root,ans);
        return ans;
    }
};