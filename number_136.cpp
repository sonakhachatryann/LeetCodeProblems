/*
Given a non-empty array of integers nums, every element 
appears twice except for one. Find that single one.

You must implement a solution with a linear runtime 
complexity and use only constant extra space.
*/

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};

/*
Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1
*/

//time complexity O(n)
//space complexity O(1)