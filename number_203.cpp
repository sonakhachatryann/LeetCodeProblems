/*
Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head) {
            ListNode* cur = head;
            ListNode* prev = head;
            while (cur != nullptr) {
                if (cur == head && cur->val == val) {
                    cur = prev->next;
                    delete prev;
                    prev = cur;
                    head = cur;
                }
                else if (val == cur->val) {
                    prev->next = cur->next;
                    delete cur;
                    cur = prev->next;
                }
                else {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};