/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p->val === q->val){
            if(p->left){
                if(q->left){
                    isSameTree(p->left , q->left);
                }
                else{
                    return false;
                }
            }
            if(p->right && q->right){
                isSameTree(p->right,q->right);
            }

        }else{
            return false;
        }
    }
};