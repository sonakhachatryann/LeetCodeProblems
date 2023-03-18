/*
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        if (head) {
            while(tmp->next) {
                if (tmp->val == tmp->next->val) {
                    ListNode* tmp1 = tmp->next;
                    tmp->next = tmp->next->next;
                    delete tmp1;
                }
                else {
                    tmp = tmp->next;
                }
                
                if (!tmp) {
                    break;
                }
            }
        }
        return head;
    }
};