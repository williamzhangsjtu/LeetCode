#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        if (!matrix.size()) return result;
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int direction = 0, cur_row = 0, cur_col = 0;
        while(up <= down && left <= right)
        {
            switch (direction)
            {
                case (0):
                {
                    for (cur_col = left; cur_col <= right; ++cur_col)
                    {
                        result.push_back(matrix[cur_row][cur_col]);
                    }
                    cur_col = right;
                    up++;
                    break;
                }
                case (1):
                {
                    for (cur_row = up; cur_row <= down; ++cur_row)
                    {
                        result.push_back(matrix[cur_row][cur_col]);
                    }
                    cur_row = down;
                    right--;
                    break;
                }
                case (2):
                {
                    for (cur_col = right; cur_col >= left; --cur_col)
                    {
                        result.push_back(matrix[cur_row][cur_col]);
                    }
                    cur_col = left;
                    down--;
                    break;
                }
                case (3):
                {
                    for (cur_row = down; cur_row >= up; --cur_row)
                    {
                        result.push_back(matrix[cur_row][cur_col]);
                    }
                    cur_row = up;
                    left++;
                    break;
                }
            }


            direction = (direction + 1) % 4;
        }
        return result;
        
    }
};