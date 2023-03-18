/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/

#include <vector>

std::vector<int> _singleNumber(std::vector<int>& nums) {
    unsigned int tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        tmp ^= nums[i];
    }
    tmp &= -tmp;
    std::vector<int> result = {0, 0};
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & tmp) {
            result[0] ^= nums[i];
        }
        else {
            result[1] ^= nums[i];
        }
    }
    return result;
}

/*
Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]
*/

//time complexity O(n)
//space complexity O(1)