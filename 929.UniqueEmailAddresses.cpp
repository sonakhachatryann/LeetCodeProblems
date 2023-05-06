/*
929. Unique Email Addresses
Every valid email consists of a local name and a domain name, 
separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, 
mail sent there will be forwarded to the same address without dots in the local name. 
Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. 
This allows certain emails to be filtered. Note that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], 
return the number of different addresses that actually receive mails.
*/

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
private:
    std::string& bringToValidForm(std::string& email) {
        bool plusSeen = false;
        bool atSeen = false;
        std::string validEmail;
        for (int i = 0; i < email.size(); ++i) {
            if (email[i] == '+') {
                plusSeen = true;
            }
            else if (email[i] == '@') {
                atSeen = true;
            }
            if (!atSeen && email[i] == '.') {
                continue;
            }
            if (plusSeen && !atSeen) {
                continue;
            }
            validEmail.push_back(email[i]);
        }
        email = validEmail;
        return email;
    }
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
        int count{};
        std::unordered_map<std::string, int> map;
        for (auto& it : emails) {
            ++map[bringToValidForm(it)];
        }
        return map.size();
    }
};

// time complexity O(n * m) where n = emails.size() and m is the maximum of emails[i].size()
// space complexity O(n)

/*
Example 1:

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com",
"testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

Example 2:

Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
*/