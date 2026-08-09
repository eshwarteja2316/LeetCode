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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l3=new ListNode();
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        int carry=0;
        ListNode*temp3=l3;
        while(temp1!=NULL&&temp2!=NULL){
            int sum=temp1->val+temp2->val+carry;
            if(sum>=10){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            temp3->next=new ListNode(sum);
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        while(temp1!=NULL){
            int sum=temp1->val+carry;
               if(sum>=10){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            temp3->next=new ListNode(sum);
            temp1=temp1->next;
            temp3=temp3->next;
        }
         while(temp2!=NULL){
            int sum=temp2->val+carry;
               if(sum>=10){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            temp3->next=new ListNode(sum);
            temp2=temp2->next;
            temp3=temp3->next;
        }
        if(carry==1){
            temp3->next=new ListNode(1);
        }
        return l3->next;
    }
};