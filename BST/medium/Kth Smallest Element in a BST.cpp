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
    void inorder(TreeNode* root, vector<int> &in) {
        if (root == NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);
        return in[k-1];
    }
};


// SC O(n)
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
    void inorder(TreeNode* root, int& cnt, int& Ksmallest, int k) {
        if (root == NULL || cnt > k)
            return;
        inorder(root->left, cnt, Ksmallest, k);
        cnt++;
        if (cnt == k) {
            Ksmallest = root->val;
            return;
        }
        inorder(root->right, cnt, Ksmallest, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int Ksmallest = 0;
        int cnt = 0;
        inorder(root, cnt, Ksmallest, k);
        return Ksmallest;
    }
};
