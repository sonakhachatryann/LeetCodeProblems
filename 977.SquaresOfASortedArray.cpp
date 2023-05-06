/*
977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.
*/

#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> result(size);
        int negativeIndex{};
        int positiveIndex{};
        bool check = false;
        // detemining the values of the indices
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                positiveIndex = i;
                negativeIndex = i - 1;
                check = true;
                break;
            }
        }
        if (!check) {
            negativeIndex = size - 1;
        }
        for (auto& it : nums) {
            it*= it;
        }
        int k{};
        while (negativeIndex >= 0 && positiveIndex < size) {
            if (nums[negativeIndex] > nums[positiveIndex]) {
                result[k++] = nums[positiveIndex++];
            }
            else {
                result[k++] = nums[negativeIndex--];
            }
        }
        while (negativeIndex >= 0 && k < size) {
            result[k++] = nums[negativeIndex--];
        }

        while (positiveIndex < size && k < size) {
            result[k++] = nums[positiveIndex++];
        }
        return result;
    }
};
// time complexity O(n)
// space complexity O(n)

/*
Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/