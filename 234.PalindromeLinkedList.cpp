/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome
or false otherwise.
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

    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode* tmp = head;
        int count{};
        while (tmp) {
            ++count;
            tmp = tmp->next;
        }
        int count2 = count / 2;
        tmp = head;
        while (count2) {
            --count2;
            tmp = tmp->next;
        }
        tmp = reverseList(tmp);
        ListNode* tmp2 = head;
        count2 = count / 2;
        while (count2) {
            if (tmp->val != tmp2->val) {
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
            --count2;
        }
        return true;
    }
};

// time complexity O(n)
// space complexity O(1)

/*
Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false
*/