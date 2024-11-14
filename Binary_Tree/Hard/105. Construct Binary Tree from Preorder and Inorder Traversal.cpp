/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.*/

class Solution {
public:
    int postion(vector<int>& inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }}
        
        return -1;

    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inorderstart,int inorderend,int &preorder_index,int t){
        if(inorderstart>inorderend || preorder_index>=t){
            return NULL;
        }
        int element=preorder[preorder_index++];
        TreeNode* root = new TreeNode(element);
        int position=postion(inorder,element);
        root->left=solve(preorder,inorder,inorderstart,position-1,preorder_index,t);
        root->right=solve(preorder,inorder,position+1,inorderend,preorder_index,t);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        int preOrderIndex=0;
        return solve(preorder,inorder,0,n-1,preOrderIndex,preorder.size());

    }
};