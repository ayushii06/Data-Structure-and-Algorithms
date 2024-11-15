/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

class Solution {
private:
TreeNode* findPred(TreeNode* node){
    TreeNode* pred = node->left;
    while(pred->right!=NULL && pred->right!=node){
        pred=pred->right;
    }
    return pred;
}
public:
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }

        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left==NULL){
                curr=curr->right;
                cout<<"run"<<endl;
            }
            else{
                TreeNode* prede = findPred(curr);
                cout<<prede->val<<endl;
                    prede->right = curr->right;
                    TreeNode* left = curr->left;
                    curr->left=NULL;
                    curr->right = left;
                
            
            }
        }
    }
};