/*
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

struct ListNode {
    int val;
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        if (head) {
            ListNode* tmp1 = nullptr;
            while(tmp->next) {
                if (tmp->val == tmp->next->val) {
                    tmp1 = tmp->next;
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

/*
Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/

//time complexity O(n)
//space complexity O(1)