class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }

    bool isBST(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return isBST(node->left, minVal, node->val) &&
               isBST(node->right, node->val, maxVal);
    }
};
