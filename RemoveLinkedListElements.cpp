/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

struct ListNode {
    int val;
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution1 {
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
//time complexity O(n)
//space complexity O(1)


class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        head->next = removeElements(head->next, val);
        if (head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }      
        return head;
    }
};
//time complexity O(n)
//space complexity O(n)


/*
Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
*/