/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* tmp1 = head;
        ListNode* tmp2 = head;
        while (tmp1->next && tmp1->next->next) {
            tmp1 = tmp1->next->next;
            tmp2 = tmp2->next;
            if (tmp1 == tmp2) {
                return true;
            }
        }
        return false;
    }
};
//time complexity O(n)
//space complexity O(1)

class Solution2 {
public:
    bool hasCycleHelper(ListNode* first, ListNode* second) {
        if (!first || !first->next) {
            return false;
        }
        if (first == second) {
            return true;
        }
        return hasCycleHelper(first->next->next, second->next);
    }
    
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        return hasCycleHelper(head->next->next, head->next);
    }
};

//time complexity O(n)
//space complexity O(n)

 /*
 Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 */