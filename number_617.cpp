/*
You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node.
*/

#include <stack>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        stack1.push(root1);
        stack2.push(root2);
        while (!stack1.empty()) {
            TreeNode* cur1 = stack1.top();
            TreeNode* cur2 = stack2.top();
            stack1.pop();
            stack2.pop();
            cur1->val += cur2->val;
            if (cur1->left && cur2->left) {
                stack1.push(cur1->left);
                stack2.push(cur2->left);
            } else if (!cur1->left) {
                cur1->left = cur2->left;
            }
            if (cur1->right && cur2->right) {
                stack1.push(cur1->right);
                stack2.push(cur2->right);
            } else if (!cur1->right) {
                cur1->right = cur2->right;
            }
        }
        return root1;
    }
};

/*
Example 1:

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]
*/

//time complexity O(n)
//space complexity O(1)