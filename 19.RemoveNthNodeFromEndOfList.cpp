/*
19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

#include <vector>

struct ListNode {
    int val;
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> myVec;
        while (head) {
            myVec.push_back(head);
            head = head->next;
        }
        int esiminch = myVec.size() - n;
        if (esiminch == 0) {
            delete myVec[0];
            if (myVec.size() == 1) {
                return nullptr;
            }
            return myVec[1];
        }
        myVec[esiminch - 1]->next = myVec[esiminch]->next;
        delete myVec[esiminch];
        return myVec[0];
    }
};

// time complexity O(n)
// space complexity O(n)

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = new ListNode;
        tmp->next = head;
        ListNode* slow = tmp;
        ListNode* fast = tmp;
        while (n) {
            fast = fast->next;
            --n;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp2 = slow->next;
        slow->next = slow->next->next;
        delete tmp2;
        return tmp->next;
    }
};

// time complexity O(n)
// space complexity O(1)

/*
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/