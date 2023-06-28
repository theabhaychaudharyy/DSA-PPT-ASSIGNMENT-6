#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> multiplySparseMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    // Initialize the result matrix with zeros
    vector<vector<int>> result(m, vector<int>(n, 0));

    // Create unordered maps to store non-zero values of mat1 and mat2
    unordered_map<int, int> mat1_dict;
    unordered_map<int, int> mat2_dict;

    // Populate the unordered maps with non-zero values of mat1 and mat2
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (mat1[i][j] != 0) {
                mat1_dict[i * k + j] = mat1[i][j];
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat2[i][j] != 0) {
                mat2_dict[i * n + j] = mat2[i][j];
            }
        }
    }

    // Perform matrix multiplication
    for (const auto& mat1_entry : mat1_dict) {
        int row = mat1_entry.first / k;
        int col1 = mat1_entry.first % k;

        for (const auto& mat2_entry : mat2_dict) {
            int col2 = mat2_entry.first % n;
            int key = col1 * n + col2;

            if (mat2_entry.first / n == col1) {
                result[row][col2] += mat1_entry.second * mat2_entry.second;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    vector<vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    vector<vector<int>> result = multiplySparseMatrices(mat1, mat2);

    // Print the result matrix
    for (const auto& row : result) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
