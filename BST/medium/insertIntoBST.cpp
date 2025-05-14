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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if (root == NULL)
            return newnode;
        TreeNode* temp = root;
        while (true) {
            if (val < temp->val) {
                if (temp->left == NULL) {
                    temp->left = newnode;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = newnode;
                    break;
                } else
                    temp = temp->right;
            }
        }

        return root;
    }
};
