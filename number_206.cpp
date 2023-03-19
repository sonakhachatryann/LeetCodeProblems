/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        if (head) {
            ListNode* tmp = head;
            ListNode* new_node = new ListNode();
            new_node->val = tmp->val;
            tmp = tmp->next;
            while (tmp) {
                ListNode* l = new_node;
                new_node = new ListNode();
                new_node->val = tmp->val;
                new_node->next = l;
                tmp = tmp->next;
            }
            return new_node;
        }
        return head;
    }
};

/*
Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []
*/

//time complexity O()
//space complexity O(n)