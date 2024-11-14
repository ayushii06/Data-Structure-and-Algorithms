/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.*/

class Solution {
public:
    int postion(vector<int>& inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }}
        
        return -1;

    }
    TreeNode* solve(vector<int>& pr, vector<int>& ir,int irstart,int irend,int &index){
        if(irstart>irend || index<0){
            return NULL;
        }
        int element=pr[index--];
        TreeNode* root = new TreeNode(element);
        int position=postion(ir,element);
        root->right=solve(pr,ir,position+1,irend,index);
        root->left=solve(pr,ir,irstart,position-1,index);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int prIndex=inorder.size()-1;
        return solve(postorder,inorder,0,inorder.size()-1,prIndex);

    }
};