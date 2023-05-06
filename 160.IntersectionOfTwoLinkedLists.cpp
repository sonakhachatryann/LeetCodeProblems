/*
160. Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        } 
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        while (tmp1) {
            while (tmp2) {
                if (tmp1 == tmp2) {
                    return tmp1;
                }
                tmp2 = tmp2->next;
            }
            tmp2 = headB;
            tmp1 = tmp1->next;
        }
        return nullptr;
    }
};
// time complexity O(n*m) where n = headA.size() and m = headB.size()
// space complexity O(1)

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        } 
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        int count1{};
        int count2{};
        while (tmp1) {
            ++count1;
            tmp1 = tmp1->next;
        }
        while (tmp2) {
            ++count2;
            tmp2 = tmp2->next;
        }
        if (count1 > count2) {
            while (count1 > count2) {
                headA = headA->next;
                --count1;
            }
        }
        else {
            while (count1 < count2) {
                headB = headB->next;
                --count2;
            }
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// time complexity O(n + m)
// space complexity O(1)

/*
 Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (
2nd node in A and 3rd node in B) are different node references. 
In other words, they point to two different locations in memory, 
while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

Example 2:

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. 
There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. 
From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, 
while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
*/