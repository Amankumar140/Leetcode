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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode * construct(vector<int>& inorder, vector<int>& postorder, int &postIdx, int left, int right){
        if (left > right)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = search(inorder, left, right, postorder[postIdx]);
        postIdx--;
        root->right = construct( inorder,postorder, postIdx, inIdx + 1, right);
        root->left = construct( inorder, postorder,postIdx, left, inIdx - 1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size() - 1;
        return construct(inorder, postorder, postidx, 0, inorder.size() - 1);
    }
};
