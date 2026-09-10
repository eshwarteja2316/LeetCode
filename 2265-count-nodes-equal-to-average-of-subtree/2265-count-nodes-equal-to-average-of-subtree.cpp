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
    int sums(TreeNode*root,int&sum,int&count){
        if(root==NULL){
            return 0;
        }
        count++;
        sum+=root->val;
        sums(root->right,sum,count);
        sums(root->left,sum,count);
        return sum/count;
    }
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            int sum=0;
            int counts=0;
            if(temp->val==sums(temp,sum,counts))
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