/*
Given an integer array nums, return an array answer such 
that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
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