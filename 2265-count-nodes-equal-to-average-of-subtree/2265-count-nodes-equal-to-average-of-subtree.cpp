/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isok(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        int sum=0,count=0;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            count++;
            sum+=temp->val;
            if(temp->right){
                q.push(temp->right);
            } 
             if(temp->left){
                q.push(temp->left);
            } 
        }
        int avg=sum/count;
        if(root->val==avg)return true;
        return false;
    }

    int averageOfSubtree(TreeNode* root) {
          queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(isok(temp))
            count++;
            if(temp->right){
                q.push(temp->right);
            } 
             if(temp->left){
                q.push(temp->left);
            } 
        }
        return count ;
    }
};