// 73
// naive sol
// TC O(m+n+z*(m*n)) SC O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> vec; // Use pair<int, int>

        // Store positions of zeroes
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    vec.push_back({i, j});
                }
            }
        }

        // Set rows and columns to zero for each zero found
        for (auto &p : vec) {
            int row = p.first;
            int col = p.second;

            // Set entire row to 0
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }

            // Set entire column to 0
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
