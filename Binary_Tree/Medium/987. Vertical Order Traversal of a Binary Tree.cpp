/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.*/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int , multiset <int> >>nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>>ans;

        if(root==NULL){
            return ans;
        }

        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(front->val);

            if(front->left){
                q.push({front->left,{hd-1,lvl+1}});
            }
            if(front->right){
                q.push({front->right,{hd+1,lvl+1}});
            }

        }
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }

            ans.push_back(col);
        }
        return ans;
    }
};