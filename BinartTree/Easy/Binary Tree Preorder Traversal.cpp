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
    void preorder(TreeNode* root, vector<int>& preOrder) {
        if (root == NULL)
            return;
        preOrder.push_back(root->val);
        preorder(root->left,preOrder);
        preorder(root->right,preOrder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        preorder(root, preOrder);
        return preOrder;
    }
};
// iterative approach
vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorder;
         if(root==NULL) return preorder;
         stack<TreeNode*>s;
         s.push(root);
         while(!s.empty()){
            root=s.top();
            s.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL) s.push(root->right);
            if(root->left!=NULL) s.push(root->left);
         }
         return preorder;
    }
