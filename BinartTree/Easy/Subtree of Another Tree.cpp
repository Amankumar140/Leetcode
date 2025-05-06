// O(n*m)
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL)
            return root == subRoot;
        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL)
            return root == subRoot;
        bool leftTree = isIdentical(root->left, subRoot->left);
        bool rightTree = isIdentical(root->right, subRoot->right);
        return (leftTree && rightTree && root->val == subRoot->val);
    }
};
