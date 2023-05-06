/*
867. Transpose Matrix
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, 
switching the matrix's row and column indices.
*/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        std::vector<int> colToRows(columns);
        std::vector<std::vector<int>> result(columns, std::vector<int>(rows));
        for (int column = 0; column < columns; ++column) {
            for (int row = 0; row < rows; ++row) {
                result[column][row] = matrix[row][column];
            }
        }
        return result;
    }
};

// time complexity O(n) where n is the size of the matrix
// space complexity O(n) where n is the size if the matrix

/*
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
*/