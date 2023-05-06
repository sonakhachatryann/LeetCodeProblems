/*
104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the 
longest path from the root node down to the farthest leaf node.
*/

#include <queue>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
			return 0;
	    }
	    std::queue<TreeNode*> queue;
	    queue.push(root);
	    int height{};
	    int node_count{};
	    TreeNode* node = nullptr;
	    while (true) {
		    node_count = queue.size();
		    if (node_count == 0) {
			    return height;
		    }   
		    ++height;
		    while (node_count != 0) {
			    node = queue.front();
			    queue.pop();
			    if (node->left != nullptr) {
				    queue.push(node->left);
			    }
			    if (node->right != nullptr) {
				    queue.push(node->right);
			    }
			    --node_count;
		    }
        }
    }
};
//time complexity O(n)
//space complexity O(n)

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
		    return 0;
	    }        
	    int first = maxDepth(root->left);
        int second = maxDepth(root->right);
        return first > second ? first + 1 : second + 1;
    }
};
//time complexity O(n)
//space complexity O(n)

/*
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:

Input: root = [1,null,2]
Output: 2
*/