class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> triangle;

        for (int row = 0; row < numRows; ++row) {
            vector<int> newRow(row + 1, 1); // initialize row with 1s

            for (int col = 1; col < row; ++col) {
                newRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }

            triangle.push_back(newRow);
        }

        return triangle; 
    }
};
