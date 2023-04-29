/*
23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <vector>

struct ListNode {
    int val;
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* merge_two_lists(ListNode* first, ListNode* second) {
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
    
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; ++i) {
            lists[i] = merge_two_lists(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}

/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/

//time complexity O(n*len*log(len)), where n = first.size + second.size, len = lists.size
//space complexity O(n*len*log(len))