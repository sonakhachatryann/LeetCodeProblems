/*
561. Array Partition
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), 
(a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
*/

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& arr, int start, int mid, int end) {
        int first1 = start;
        int last1 = mid;
        int first2 = mid + 1;
        int last2 = end;
        int index{};
        std::vector<int> tmp(end - start + 1);
        while (first1 <= last1 && first2 <= last2) {
            if (arr[first1] < arr[first2]) {
                tmp[index++] = arr[first1++];
            }
            else {
                tmp[index++] = arr[first2++];
            }
        }
        while (first1 <= last1) {
            tmp[index++] = arr[first1++];
        }
        while (first2 <= last2) {
            tmp[index++] = arr[first2++];
        }
        for (int i = 0; i < index; ++i) {
            arr[i + start] = tmp[i];
        }
    }

    void mergesort(std::vector<int>& arr, int start, int end) {
        if (start >= end) {
            return ;
        }
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    int arrayPairSum(std::vector<int>& nums) 
    {
        mergesort(nums, 0, nums.size() - 1);
        int sum{};
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];        
        }
        return sum;
    }
};

// time complexity O(nlogn)
// space complexity O(n)

/*
Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.

Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). 
min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
*/