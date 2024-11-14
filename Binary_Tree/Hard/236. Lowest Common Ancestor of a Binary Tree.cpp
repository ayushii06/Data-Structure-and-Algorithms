/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.*/

class Solution {
private:
    TreeNode* solve(TreeNode* &root , TreeNode* &p , TreeNode* &q){
        if(root == NULL||root->val == p->val||root->val== q->val){
            return root;
        }
      

        TreeNode* leftAns = solve(root->left,p,q);
        TreeNode* rightAns = solve(root->right,p,q);

        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else{
            return NULL;
        }

        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root->val==p->val || root->val ==q->val){
            return root;
        }

        TreeNode* ans = solve(root,p,q);
        return ans;

        
    }
};