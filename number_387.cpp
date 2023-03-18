/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.
*/

#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        const int size = 26;
        int arr[size] {};
        for (int i = 0; i < s.size(); ++i) {
            ++arr[s[i] - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (arr[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

/*
Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1
*/

//time complexity O(n)
//space complexity O(1)