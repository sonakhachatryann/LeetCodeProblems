/*
Given a binary tree, determine if it is height-balanced.
*/

#include <queue>
#include <stack>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* tmp;
        int nodeCount{};
        int height{};
        while (!queue.empty()) {
            nodeCount = queue.size();
            ++height;
            while (nodeCount) {
                tmp = queue.front();
                queue.pop();
                if (tmp->left) {
                    queue.push(tmp->left);
                }
                if (tmp->right) {
                    queue.push(tmp->right);
                }
                --nodeCount;
            }            
        }
        return height;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        std::stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* tmp;
        while (!stack.empty()) {
            tmp = stack.top();
            stack.pop();
            if (abs(height(tmp->right) - height(tmp->left)) > 1) {
                return false;
            }
            if (tmp->left) {
                stack.push(tmp->left);
            }
            if (tmp->right) {
                stack.push(tmp->right);
            }
        }
        return true;
    }
};

/*
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
*/

//time complexity O(n^2)
//space complexity O(1)