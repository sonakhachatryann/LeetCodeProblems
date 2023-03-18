/*
Given an integer array nums, return an array answer such 
that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        int temp1 = 1;
        int i = 1;
        for (; i < nums.size(); ++i) {
            temp1 *= nums[i - 1];
            result[i] *= temp1;
        }
        int temp2 = 1;
        for (int j = nums.size() - 2; j >= 0; --j) {
            temp2 *= nums[i - 1];
            result[j] *= temp2;
            --i;
        }
        return result;
    }
};

/*
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

//time complexity O(n)
//space complexity O(1)