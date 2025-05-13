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

    void inorder(TreeNode* root, vector<int>& inOrder) {
        if (root == NULL)
            return;
        
        inorder(root->left,inOrder);
        inOrder.push_back(root->val);
        inorder(root->right,inOrder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        inorder(root,inOrder);
        return inOrder;
    }
};
// iterative approach
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> s;
        TreeNode* current = root;
       
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            inOrder.push_back(current->val);
            current = current->right;
        }
        return inOrder;
    }
};


// morris traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                inOrder.push_back(curr->val);
                curr = curr->right;

            } else {
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr)
                    IP = IP->right;
                if (IP->right == NULL) {
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    inOrder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inOrder;
    }
};
