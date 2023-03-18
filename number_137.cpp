/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <vector>

int singleNumber(std::vector<int>& nums) {
    int size_of_int = sizeof(int) * 8;
    int tmp = size_of_int;
    int result = 0;
    unsigned int shift = 1;
    int j = 0;
    while (tmp) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & shift) {
                ++count;
            }
        }
        if (count % 3 == 1) {
            result |= (1 << j);
        }
        ++j;
        shift <<= 1;
        --tmp;
    }
    return result;
}

/*
Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

//time complexity O(32*n) = O(n)
//space complexity O(1)