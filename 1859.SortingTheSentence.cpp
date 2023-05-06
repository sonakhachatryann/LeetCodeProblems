/*
1859. Sorting the Sentence
Given a shuffled sentence s containing no more than 9 words, 
reconstruct and return the original sentence.
*/

#include <string>

class Solution {
public:
    std::string sortSentence(std::string s) {
        s += ' ';
        std::string arr[11] {};
        int k{};
        std::string currentString{};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                currentString = "";
                for (int j = k; j < i - 1; ++j) {
                    currentString += s[j];
                }
                arr[s[i - 1] - '0'] = currentString;
                k = i + 1;
            }
        }
        std::string result{};
        int curIndex{};
        for (int i = 1; i <= 10; ++i) {
            if (arr[i] == "") {
                curIndex = i - 1;
                break;
            }
        }
        for (int i = 1; i <= curIndex - 1; ++i) {
            result += arr[i];
            result += " ";
        }
        result += arr[curIndex];        
        return result;
    }
};

// time complexity O(n^2)
// space complexity O(n)

/*
Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions 
"This1 is2 a3 sentence4", then remove the numbers.

Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions 
"Me1 Myself2 and3 I4", then remove the numbers.
*/