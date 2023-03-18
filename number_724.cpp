/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the 
index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 
because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        std::vector<int> leftIndex(nums.size(), 0);
        std::vector<int> rightIndex(nums.size(), 0);
        int tmp1{};
        for (int i = 1; i < nums.size(); ++i) {
            tmp1 += nums[i - 1];
            leftIndex[i] = tmp1;
        }
        int tmp2{};
        for (int j = nums.size() - 2; j >= 0; --j) {
            tmp2 += nums[j + 1];
            rightIndex[j] = tmp2;
        }
        for (int k = 0; k < nums.size(); ++k) {
            if (leftIndex[k] == rightIndex[k]) {
                return k;
            }
        }
        return -1;
    }  
};

/*
Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/

//time complexity O(n)
//space complexity O(n)