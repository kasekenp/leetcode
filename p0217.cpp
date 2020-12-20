#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> priorNums;
        for (auto num : nums)
        {
            if (priorNums.find(num) != priorNums.end())
            {
                return true;
            }
            priorNums.insert(num, 0);
        }
        return false;
    }
};