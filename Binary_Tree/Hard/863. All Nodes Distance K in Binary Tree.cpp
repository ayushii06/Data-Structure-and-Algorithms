/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.*/


class Solution {
private:
TreeNode* createMap(TreeNode* root,TreeNode* target, map<TreeNode* ,TreeNode*> &nodeToParent){
    if(root==NULL){
        return NULL;
    }

    queue<TreeNode* > q;
    q.push(root);
    nodeToParent[root]=NULL;
    TreeNode* res = NULL;
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();

        if(front->val==target->val)
        {
        res= front;
        }

        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}

void solve(TreeNode*root,TreeNode* target, map<TreeNode* , bool>&visited,int k,vector<int>&ans,map<TreeNode* , TreeNode*>nodeToParent){
   if(k==0 && root!=NULL && root!=target){
    ans.push_back(root->val);
    return ;
   }

   if(root==NULL){
    return;
   }

   if(root->left && !visited[root->left]){
    k--;
    visited[root->left]=true;
   solve(root->left,target,visited,k,ans,nodeToParent);
   k++;
   }
   if(root->right && !visited[root->right]){
    k--;
    visited[root->right]=true;
   solve(root->right,target,visited,k,ans,nodeToParent);
   k++;

   }

   if(!visited[nodeToParent[root]] && nodeToParent[root]!=NULL){
    k--;
    visited[nodeToParent[root]]=true;
   solve(nodeToParent[root],target,visited,k,ans,nodeToParent);
   k++;
   }
   return ;

}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

        map<TreeNode* , TreeNode*>nodeToParent;
        map<TreeNode* , bool>visited;
        TreeNode* node = createMap(root,target,nodeToParent);
        if(k==0){
            ans.push_back(node->val);
            return ans;
        }
        visited[node]=true;
        solve(node,target,visited,k,ans,nodeToParent);
        return ans;
        
    }
};