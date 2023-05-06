/*
169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count{};
        int currentElement{};
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                currentElement = nums[i];
            }
            if (nums[i] == currentElement) {
                ++count;
            }
            else {
                --count;
            }
        }
        return currentElement;
    }
};

// time complexity O(n)
// space complexity O(1)

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size() / 2;
        std::unordered_map<int, int> myMap;
        for (auto& it : nums) {
            ++myMap[it];
        }
        for (auto& it : myMap) {
            if (it.second > n) {
                return it.first;
            }
        }
        return -1;
    }
};
// time complexity O(n)
// space complexity O(n)

/*
Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/