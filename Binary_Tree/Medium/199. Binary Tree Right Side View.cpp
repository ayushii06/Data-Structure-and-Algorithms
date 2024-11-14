/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.*/

class Solution {
private:
    void solve(TreeNode* root, vector<int>& ans , int level){
        if(root==NULL){
            return ;
        }

        if(level == ans.size()){
            ans.push_back(root->val);
        }

        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};