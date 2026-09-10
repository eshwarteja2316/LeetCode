/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool backtrack(TreeNode*root,ListNode*head){
        if(head->next==NULL){
            if(head->val==root->val){
                return true;
            }
            return false;
        }
        if(root==NULL){
            return false;
        }
        if(root->val==head->val){
            if(root->left&&root->right)
            return backtrack(root->left,head->next)||backtrack(root->right,head->next);
            else if(root->left)
             return backtrack(root->left,head->next);
            else if(root->right){
                return backtrack(root->right,head->next);
            }
        }
            return false;
    }
    bool isok(ListNode*root,TreeNode*head){
        if(head==NULL){
            return false;
        }
        if(root->val==head->val){
            if(backtrack(head,root)){
                return true;
            }
        }
        return isok(root,head->left)||isok(root,head->right);;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(isok(head,root)){
            return true;
        }
        return false;
    }
};