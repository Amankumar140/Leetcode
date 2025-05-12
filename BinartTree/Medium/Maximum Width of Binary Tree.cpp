//Goal:
// Find the maximum width of a binary tree.
// Width of a level = index of rightmost node - index of leftmost node + 1.
// Steps:
// Use level-order traversal (BFS) with a queue.
// For each node, keep track of its index (like in a complete binary tree):
// Left child index = 2 * parent_index + 1
// Right child index = 2 * parent_index + 2
// For each level:
// Record the first and last node indices.
// Width = last_index - first_index + 1
// Update maxWidth accordingly.
// Normalize indices at each level to avoid integer overflow by subtracting the first index of that level.

//TC O(n) SC O(n)

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (q.size() > 0) {
            int currSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long enIdx = q.back().second;
            maxWidth = max(maxWidth, (int)(enIdx - stIdx + 1));
            for (int i = 0; i < currSize; i++) {
                auto curr = q.front();
                q.pop();
                if (curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }
        return maxWidth;
    }
};
