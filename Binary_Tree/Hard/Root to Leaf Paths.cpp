/*
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
*/
class Solution {
private:
    void rec(Node* root , vector<vector<int>>&ans , vector<int> temp){
       if(root==NULL){
           return;
       }
       if(root->left==NULL && root->right == NULL){
           temp.push_back(root->data);
           ans.push_back(temp);
           return ;
       }
       temp.push_back(root->data);
       rec(root->left,ans,temp);
       rec(root->right,ans,temp);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        vector<int> temp;
        
        rec(root,ans,temp);
        return ans;
        
        
    }
};