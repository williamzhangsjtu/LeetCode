#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if (!matrix.size()) return;
        bool row_1 = false, col_1 = false;
        for (int row = 1; row < matrix.size(); ++row) 
        {
            if (!matrix[row][0]) {col_1 = true; break;}
        }
        for (int col = 1; col < matrix[0].size(); ++col) 
        {
            if (!matrix[0][col]) {row_1 = true; break;}
        }
        if (!matrix[0][0]) {row_1 = true, col_1 = true;}
        for (int row = 1; row < matrix.size(); ++row)
        {
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (!matrix[row][col])
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for (int row = 1; row < matrix.size(); ++row)
        {
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (!matrix[0][col] || !matrix[row][0])
                {
                    matrix[row][col] = 0;
                }
            }
        }
        if (row_1) for (int col = 0; col < matrix[0].size(); ++col) matrix[0][col] = 0;
        if (col_1) for (int row = 0; row < matrix.size(); ++row)  matrix[row][0] = 0;
    }
};