/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
//time complexity O(n)
//space complexity O(n)


class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* tmp = head;
        int size{};
        while (tmp) {
            tmp = tmp->next;
            ++size;
        }
        tmp = head;
        std::vector<ListNode*> vec(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = tmp;
            tmp = tmp->next;
        }
        for (int i = size - 1; i > 0; --i) {
            vec[i]->next = vec[i - 1];
        }
        head = vec[size - 1];
        vec[0]->next = nullptr;
        return head;
    }
};
//time complexity O(n)
//space complexity O(n)


class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head && head->next) {
            ListNode* first = head;
            ListNode* second = first->next;
            ListNode* third = second->next;
            first->next = nullptr;
            second->next = first;
            first = second;
            second = third;
            if (!third) {
                return first;
            }
            third = third->next;
            while (third) {
                second->next = first;
                first = second;
                second = third;
                third = third->next;
            }
            second->next = first;
            head = second;
        }
        return head;
    }
};
//time complexity O(n)
//space complexity O(1)

class Solution4 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* reversed = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversed;
    }
};
//time complexity O(n)
//space complexity O(n)


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