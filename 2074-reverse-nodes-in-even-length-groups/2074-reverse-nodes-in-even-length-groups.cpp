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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;

        int groupSize = 1;

        while (curr != nullptr) {
            ListNode* groupStart=curr;

            int count=0;
            ListNode* temp = curr;

        while (temp != nullptr && count < groupSize) {
            count++;
            temp=temp->next;
        }
        if (count % 2 == 0) {
            ListNode* before=prev;
            ListNode* nextGroup=temp;

            for (int i=0;i<count;i++) {
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if (before != nullptr) {
                before->next=prev;
            }
            else {
                head = prev;
            }
            groupStart->next=nextGroup;
            prev=groupStart;
        }
        else {
            for (int i=0;i<count;i++) {
                prev=curr;
                curr=curr->next;
            }
        }
        groupSize++;
        }
        return head;
    }
};