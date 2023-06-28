#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    
    while (num <= n * n) {
        // Traverse top row from left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        
        // Traverse right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        
        // Traverse bottom row from right to left
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;
        
        // Traverse left column from bottom to top
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }
    
    return matrix;
}

int main() {
    int n = 3;
    std::vector<std::vector<int>> matrix = generateMatrix(n);
    
    std::cout << "Spiral Matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
