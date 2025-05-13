// Mark Parent Nodes (Preprocessing):
// Use a BFS traversal to build a map (parent_track) that records each node's parent.
// This helps you move up the tree since TreeNode does not have a parent pointer by default.
// BFS from Target Node:
// Start a BFS from the target node.
// Use a visited map to avoid revisiting nodes.
// At each level of BFS (representing increasing distance), increment the distance counter curr_level.
// Stop the BFS when curr_level == k.
// Collect Result:
// All nodes remaining in the queue after k levels are the nodes at distance k from the target.
// Collect their values into the answer vector.
// TC O(n) SC O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track,
                    TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int curr_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    ;
                    q.push(curr->left);
                }
                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    ;
                    q.push(curr->right);
                }
                if (parent_track[curr] && !vis[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};
