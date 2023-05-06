/*
217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.
*/

#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            ++myMap[nums[i]];
        }
        for (auto& it : myMap) {
            if (it.second > 1) {
                return true;
            }
        }
        return false;
    }
};
// time complexity O(n)
// space complexity O(n)

/*
Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/