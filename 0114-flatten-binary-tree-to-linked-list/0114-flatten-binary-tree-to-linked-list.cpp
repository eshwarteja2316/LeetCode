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
    void tovector(TreeNode*root,vector<TreeNode*>&nums){
        if(root==NULL){
            return;
        }
        nums.push_back(root);
        tovector(root->left,nums);
        tovector(root->right,nums);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        vector<TreeNode*>nums;
        tovector(root,nums);
        TreeNode*temp=root;
        for(int i=1;i<nums.size();i++){
            temp->right=nums[i];
            temp->left=NULL;
            temp=temp->right;
        }
    }
};