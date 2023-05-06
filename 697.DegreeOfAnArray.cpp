/*
697. Degree of an Array
Given a non-empty array of non-negative integers nums, 
the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, 
that has the same degree as nums.
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }
        int max = map[0];
        int firstOfMax{};
        for (auto& it : map) {
            if (it.second > max) {
                max = it.second;
                firstOfMax = it.first;
            }
        }
        int result = nums.size();
        for (auto& it : map) {
            if (it.second == max) {
                int firstIndex{};
                for (int i = 0; i < nums.size(); ++i) {
                    if (nums[i] == it.first) {
                        firstIndex =  i;
                        break;
                    }
                }
                int secondIndex{};
                for (int i = nums.size() - 1; i >= 0; --i) {
                    if (nums[i] == it.first) {
                        secondIndex =  i;
                        break;
                    }
                }
                if (result > secondIndex - firstIndex + 1) {
                    result = secondIndex - firstIndex + 1;
                }
            }
            
        }
        return result;
    }
};

// time complexity O(n^2)
// space complexity O(n)

/*
Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
*/