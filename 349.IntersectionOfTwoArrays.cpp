/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.
*/

#include <vector>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int size = nums1.size() + nums2.size();
        int quantities1[1000]{};
        int quantities2[1000]{};
        for (int i = 0; i < nums1.size(); ++i) {
            ++quantities1[nums1[i]];
        }
        for (int i = 0; i < nums2.size(); ++i) {
            ++quantities2[nums2[i]];
        }
        std::vector<int> result;
        for (int i = 0; i < 1000; ++i) {
            if (quantities1[i] != 0  && quantities2[i] != 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// time complexity O(n)
// space complexity O(n)

/*
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/