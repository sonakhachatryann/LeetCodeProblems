/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur || !stack.empty()) {
            if (cur != nullptr) {
			stack.push(cur);
			cur = cur->left;
		    }
		    else {
			    cur = stack.top();
			    stack.pop();
			    result.push_back(cur->val);
			    cur = cur->right;
		    }
        }  
        return result;
    }
};

/*
Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
*/

//time complexity O(n)
//space complexity O(n)