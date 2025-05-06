/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int leftDia= diameterOfBinaryTree(root->left);
        int rightDia= diameterOfBinaryTree(root->right);

        int currDia=height(root->left) +height(root->right);
        return max(max(leftDia, rightDia), currDia);
    }

    int height(TreeNode * root){
        if(root==NULL) return 0;
        int lheight=height(root->left);
        int rHeight=height(root->right);
        return max(rHeight,lheight)+1;
    }
};
