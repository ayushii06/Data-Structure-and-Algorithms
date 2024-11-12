/*Given a binary tree, determine if it is 
height-balanced
.*/

class Solution {
private:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool ans = false;

        if (abs(height(root->left) - height(root->right)) <= 1) {
            ans = true;
        }

        return left && right && ans;
    }
};