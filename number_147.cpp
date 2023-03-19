/*
Given the head of a singly linked list, sort the list using insertion sort, 
and return the sorted list's head.
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
    ListNode* insertionSortList(ListNode* head) {
        if (head) {
            ListNode* empty = new ListNode();
            empty->next = head;
            ListNode* prev = head;
            ListNode* cur = head->next;
            ListNode* tmp = nullptr;
            while (cur) {
                if (cur->val < prev->val) {
                    tmp = empty;
                    while (tmp->next->val < cur->val) {
                        tmp = tmp->next;
                    }
                    prev->next = cur->next;
                    cur->next = tmp->next;
                    tmp->next = cur;
                    cur = prev->next;
                }
                else {
                    prev = cur;
                    cur = cur->next;
                }
            }
            return empty->next;
        } 
        return head;
    }
};

/*
Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/

//time complexity O()
//space complexity O()