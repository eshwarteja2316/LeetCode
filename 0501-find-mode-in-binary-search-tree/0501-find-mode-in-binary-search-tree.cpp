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
    vector<int> ans;
    int count = 0;
    int maxCount = 0;
    int prev = 0;
    bool hasprev = false;
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root) {
        if (root == nullptr) 
        return;

    inorder(root->left);
    if (hasprev && root->val == prev) {
        count++;
    }
    else {
        count = 1;
    }
    if (count > maxCount) {
        maxCount = count;
        ans.clear();
        ans.push_back(root->val);
    }
    else if (count == maxCount) {
        ans.push_back(root->val);
    }
    prev = root->val;
    hasprev = true;

    inorder (root->right);
}
};