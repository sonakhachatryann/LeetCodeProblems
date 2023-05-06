/*
1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    void merge(std::vector<std::pair<int, int>>& arr, int start, int mid, int end) 
    {
        int first1 = start;
        int last1 = mid;
        int first2 = mid + 1;
        int last2 = end;
        std::vector<std::pair<int, int>> tmp(arr.size());
        int index{};
        while (first1 <= last1 && first2 <= last2) {
            if (arr[first1].second < arr[first2].second) {
                tmp[index++] = arr[first1++];
            }
            else if (arr[first1].second > arr[first2].second) {
                tmp[index++] = arr[first2++];
            }
            else {
                if (arr[first1].first >= arr[first2].first) {
                    tmp[index++] = arr[first1++];
                }
                else {
                    tmp[index++] = arr[first2++];
                }
            }
        }
        while (first1 <= last1) {
            tmp[index++] = arr[first1++];
        }
        while (first2 <= last2) {
            tmp[index++] = arr[first2++];
        }
        for (int i = 0; i < index; ++i) {
            arr[i + start] = tmp[i];
        }
    }
    
    void mergesort(std::vector<std::pair<int, int>>& arr, int start, int end) 
    {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    
    std::vector<int> frequencySort(std::vector<int>& nums)
    {
        std::unordered_map<int, int> myMap{};
        for (int i = 0; i < nums.size(); ++i) {
            ++myMap[nums[i]];
        }
        int size = myMap.size();
        std::vector<std::pair<int, int>> result;
        for (auto& it : myMap) {
            result.push_back(it);
        }
        mergesort(result, 0, result.size() - 1);
        std::vector<int> finalResult(nums.size());
        int index{};
        for (auto& it : result) {
            for (int i = 0; i < it.second; ++i) {
                finalResult[index++] = it.first;
            }
        }
        return finalResult;
    }
};

// time complexity O(n^2)
// space complexity O(n)

/*
Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
*/