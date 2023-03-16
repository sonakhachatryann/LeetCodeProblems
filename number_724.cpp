/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the 
index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 
because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftIndex(nums.size(), 0);
        vector<int> rightIndex(nums.size(), 0);
        int tmp1{};
        for (int i = 1; i < nums.size(); ++i) {
            tmp1 += nums[i - 1];
            leftIndex[i] = tmp1;
        }
        int tmp2{};
        for (int j = nums.size() - 2; j >= 0; --j) {
            tmp2 += nums[j + 1];
            rightIndex[j] = tmp2;
        }
        for (int k = 0; k < nums.size(); ++k) {
            if (leftIndex[k] == rightIndex[k]) {
                return k;
            }
        }
        return -1;
    }  
};