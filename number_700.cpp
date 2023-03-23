/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* tmp = root;
        while (tmp) {
            if (val == tmp->val) {
                return tmp;
            }
            else if (val < tmp->val) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        return nullptr;        
    }
};
//time complexity O(log n)
//space complexity O(1)

class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        }   
        if (root->val < val) {
            return searchBST(root->right, val);
        } 
        else if (root->val > val) {
            return searchBST(root->left, val);
        }
        return nullptr;
    }
};
//time complexity O(log n)
//space complexity O(n)

/*
Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []
*/

