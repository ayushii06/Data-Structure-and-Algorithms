/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

class Solution {
private:
    int recursiveSoln(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftH = 0;
        int rightH = 0;

        if(root->left){
            leftH = 1 + recursiveSoln(root->left);
        }
        if(root->right){
            rightH = 1 + recursiveSoln(root->right);
        }

        return  max(leftH,rightH);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        return 1 + recursiveSoln(root);
    }
};