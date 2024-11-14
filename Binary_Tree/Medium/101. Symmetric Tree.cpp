/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

class Solution {
private:
    bool rec(TreeNode* root1 , TreeNode* root2){
        if(root1==NULL && root2 ==NULL){return true;}
        if(root1==NULL || root2==NULL){return false;}
        bool ans = true;
        if(root1->val !=root2->val){
            ans = false;
        }

        return ans && rec(root1->left,root2->right) && rec(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){return true;}
        return rec(root->left,root->right);
    }
};