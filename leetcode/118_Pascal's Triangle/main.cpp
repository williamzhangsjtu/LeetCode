#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        vector<int> tmp(1,1);
        if (!numRows) return result;
        result.push_back(tmp);
        int num = 1;
        for (int n = 1; n < numRows; ++i)
        {
            tmp.clear();
            num = 1;
            for (int r = 0; r <= i; ++j)
            {
                tmp.push_back(num);
                num *= (n - r);
                nums /= (r + 1);
            }
            result.push_back(tmp);
        }
        return result;
    }
};

// n!/r!(n - r)!