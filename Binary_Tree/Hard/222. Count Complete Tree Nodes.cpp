/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.*/

class Solution {
private:
int findHeight(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int leftAns = 1+findHeight(root->left);
    return leftAns;

}
    int countLeafNodes(TreeNode* root,int k){

        if(root->left==NULL && root->right==NULL && k==1){
            cout<<"k "<<k;
            return 1;
        }

int left=0;
int right =0;
        if(root->left){
            cout<<"left k "<<k<<endl;
            k=k-1;
           left  = countLeafNodes(root->left,k);
           k=k+1;
        }
        if(root->right){
            cout<<"left k "<<k<<endl;
        k=k-1;
           right = countLeafNodes(root->right,k--);
           k=k+1;
        }
        return left+right;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int height = findHeight(root);
        int total_leaf_nodes = countLeafNodes(root,height);
        cout<<total_leaf_nodes<<"   "<<height;

int sum=0;
        for(int i = 0;i<height-1;i++){
            sum+=pow(2,i);
        }
        
        return sum+total_leaf_nodes;
    }
};