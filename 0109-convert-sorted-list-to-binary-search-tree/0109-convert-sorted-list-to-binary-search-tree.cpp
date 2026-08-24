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
    TreeNode*Binarytree(vector<int>&nums){
        if(nums.size()==0){
            return NULL;
        }
        int mid=nums.size()/2;
        TreeNode*root=new TreeNode(nums[mid]);
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid+1,nums.end());
        root->left=Binarytree(left);
        root->right=Binarytree(right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int>nums;
        ListNode*temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        return Binarytree(nums);
    }
};