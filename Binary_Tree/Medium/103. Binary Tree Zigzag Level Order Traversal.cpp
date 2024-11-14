/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/

class Solution {
private:
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> result;

        if(root == NULL){
            return result;
        }

        
        queue<TreeNode*>q;
        q.push(root);
        bool LeftToRight = true;

        while(!q.empty()){
            int s = q.size();
            vector<int> ans(s);

            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = LeftToRight ? i : s-i-1;
                ans[index] = temp->val;

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

                
            }
            if(LeftToRight){
                    LeftToRight = false;
                }else{
                    LeftToRight = true;
                }
            result.push_back(ans);
        }

        return result;

    }
};