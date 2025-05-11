// Calculates the maximum gain from left and right subtrees.
// Computes the maximum path through the node (left + root + right).
// Updates a global max if this path is greater.
// Returns the max single path downward (root + max(left, right)) to parent.
//TC O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));
        int currentPath = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPath);   
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
