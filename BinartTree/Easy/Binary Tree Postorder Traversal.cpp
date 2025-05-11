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
    void postorder(TreeNode* root, vector<int>& postOrder) {
        if (root == NULL)
            return;

        postorder(root->left, postOrder);

        postorder(root->right, postOrder);
        postOrder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        postorder(root, postOrder);
        return postOrder;
    }
};
// iterative apporoach one stack uses
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
     
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (!s.empty() || current) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = s.top();
            if (peekNode->right && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                result.push_back(peekNode->val);
                lastVisited = peekNode;
                s.pop();
            }
        }
    }

    return result;
    }
};
