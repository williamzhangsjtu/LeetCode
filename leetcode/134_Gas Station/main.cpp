#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int begin = -1, tank = 0;
        int sum_1 = 0, sum_2 = 0, diff = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            diff = gas[i] - cost[i]
            sum_2 += diff;
            if (begin < 0)
            {
                if (diff >= 0)
                {
                    begin = i;
                    tank = gas[i] - cost[i];
                }
                else sum_1 += diff;
            }
            else
            {
                tank += gas[i] - cost[i];
                if (tank < 0)
                {
                    begin = -1;
                    sum_1 = sum_2;
                }
            }
            
        }
        if (begin < 0) return -1;
        if (tank >= sum_1) return begin;
        return -1;
    }
};