/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]
*/

class Solution {
    private:
    void postOrder(TreeNode* root,vector <int> &post_order){
       if(root==NULL){
           return ;
       }
        if(root->left){
            postOrder(root->left,post_order);            
        }
        if(root->right){
            postOrder(root->right,post_order);
        }
        post_order.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post_order;
        postOrder(root,post_order);
        return post_order;
    }
};