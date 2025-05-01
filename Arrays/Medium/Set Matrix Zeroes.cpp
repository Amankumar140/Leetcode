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

// optimal approach
// O(2*(n*m))
// SC O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0 = 1;
        // step 1: Traverse the matrix and
        // mark 1st row & col accordingly:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark i-th row:
                    matrix[i][0] = 0;

                    // mark j-th column:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // step 3: Finally mark the 1st col & then 1st row:
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

