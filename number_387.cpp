/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
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