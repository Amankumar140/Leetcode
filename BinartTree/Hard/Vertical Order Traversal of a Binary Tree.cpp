//Data structure used:

// map<int, map<int, multiset<int>>> nodes;
// Outer int: column (left to right)
// Inner int: row (top to bottom)
// multiset<int>: stores multiple values and keeps them sorted automatically
// Queue stores: each node with its row and column position
// After traversal, we iterate column-wise and row-wise and collect values.
// 🕒 Time & Space Complexity:
// Time: O(n log n)
// Due to map and multiset insertions and sorting
// Space: O(n)
// For queue and storage of all nodes



class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<col, map<row, multiset<val>>>
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q; // node, row, col

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, row + 1, col - 1});
            if (node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> result;

        for (auto& col_pair : nodes) {
            vector<int> col_vals;
            for (auto& row_pair : col_pair.second) {
                col_vals.insert(col_vals.end(), row_pair.second.begin(), row_pair.second.end());
            }
            result.push_back(col_vals);
        }

        return result;
    }
};
