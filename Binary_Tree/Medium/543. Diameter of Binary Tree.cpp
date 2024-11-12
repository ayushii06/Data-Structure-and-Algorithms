/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

class Solution {
private:
    int recursiveSoln(TreeNode* root, int&ans){
        if(root==NULL){
            return 0;
        }

        int leftH = 0;
        int rightH = 0;
      

        if(root->left){
            leftH = 1 + recursiveSoln(root->left,ans);
        }
        if(root->right){
            rightH = 1 + recursiveSoln(root->right,ans);
        }

        if(leftH+rightH >= ans){
            ans = leftH+rightH;
        }
        
        return max(leftH,rightH);

        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        recursiveSoln(root,ans);
        return ans;
    }
};