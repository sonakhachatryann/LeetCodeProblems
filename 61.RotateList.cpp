/*
61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* tmp = head;
        int count = 1;
        while (tmp->next) {
            tmp = tmp->next;
            ++count;
        }
        int n = count - k % count;
        tmp->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        while (n) {
            prev = prev->next;
            current = current->next;
            --n;
        }
        prev->next = nullptr;
        head = current;
        delete dummy;
        return head;
    }
};

// time complexity O(n)
// space complexity O(1)

/*
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/