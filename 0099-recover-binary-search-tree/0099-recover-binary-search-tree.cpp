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
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        TreeNode* prev = nullptr;

        void inorder(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            inorder(root->left);

            if (prev != nullptr && prev->val > root->val) {
                if (first == nullptr) {
                    first = prev;
                    middle = root;
                }
                else {
                    last = root;
                }
            }
            prev = root;
            inorder(root->right);
        }
        void recoverTree(TreeNode* root) {
            first = middle = last = prev = nullptr;
            inorder(root);
            if (last != nullptr) {
                swap(first->val, last->val);
            }
            else {
                swap(first->val, middle->val);
            }
        }
    };