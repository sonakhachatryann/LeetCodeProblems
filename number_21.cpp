/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first == nullptr){
            return second;
        }
        if(second == nullptr){
            return first;
        }
        ListNode* tmp1 = first;
        ListNode* tmp2 = second;
        ListNode* result = new ListNode();
        ListNode* tmp = result;
        while (tmp1 && tmp2) {
            ListNode* current = new ListNode();
            if (tmp1->val <= tmp2->val) {
                current->val = tmp1->val;
                tmp1 = tmp1->next;
            }
            else {
                current->val = tmp2->val;
                tmp2 = tmp2->next;
            }
            tmp->next = current;
            tmp = tmp->next;
        }
        while (tmp1) {
            ListNode* current = new ListNode();
            current->val = tmp1->val;
            tmp->next = current;
            tmp1 = tmp1->next;
            tmp = tmp->next;
        }
        while (tmp2) {
            ListNode* current = new ListNode();
            current->val = tmp2->val;
            tmp->next = current;
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        tmp = result;
        result = result->next;
        delete tmp;
        return result;
    }
};
//time complexity O(n + m)
//space Complexity O(n + m)


class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if (!first) {
            return second;
        }
        if (!second) {
            return first;
        }
        if (first->val <= second->val) {
            first->next = mergeTwoLists(first->next, second);
            return first;
        }
        else {
            second->next = mergeTwoLists(first, second->next);
            return second;
        }
    }
};
//time complexity O(n+m)
//space complexity O(1)


/*
Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/
