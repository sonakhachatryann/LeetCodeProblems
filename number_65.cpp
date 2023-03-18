/*
Given a string s, return true if s is a valid number.
*/

#include <string>

bool isNumber(std::string s) {
        bool number_seen = false;
        bool e_seen = false;
        bool dot_seen = false;
        bool number_after_e_seen = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                number_seen = true;
                number_after_e_seen = true;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (e_seen || !number_seen) {
                    return false;
                }
                e_seen = true;
                number_after_e_seen = false;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0) {
                    if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                        return false;    
                    }
                }
            }
            else if (s[i] == '.') {
                if (dot_seen || e_seen) {
                    return false;
                }
                dot_seen = true;
            }
            else {
                return false;
            }
        }
        return number_seen && number_after_e_seen;
}

/*
All the following are valid numbers: ["2", "0089", 
"-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", 
"+6e-1", "53.5e93", "-123.456e789"]
*/

/*
Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
*/

//time complexity O(s.size)
//space complexity O(1)