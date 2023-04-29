/*
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <string>

class Solution {
public:
    void toLowerCase(std::string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
    }
    
    bool isValidCharecter(char ch) {
        bool num = (ch >= '0' && ch <= '9');
        bool lowerCase = (ch >= 'a' && ch <= 'z');
        return (num || lowerCase);
    }   
    
    bool isPalindrome(std::string s) {
        int size = s.size();
        toLowerCase(s);
        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            while (!isValidCharecter(s[i]) && i < j) {
                ++i;
            }
            while (!isValidCharecter(s[j]) && i < j) {
                --j;
            }
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

/*
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

//time complexity O(n)
//space complexity O(1)