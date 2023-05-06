/*
86. Partition List
Given the head of a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode;
        ListNode* right = new ListNode;
        ListNode* tmp1 = left;
        ListNode* tmp2 = right;
        ListNode* tmp = head;
        while (tmp) {
            if (tmp->val < x) {
                tmp1->next = tmp;
                tmp1 = tmp1->next;
            } 
            else {
                tmp2->next = tmp;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        tmp1->next = right->next;
        tmp2->next = nullptr;
        return left->next;
    }
};

// time complexity O(n)
// space complexity O(1)

/*
Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
*/