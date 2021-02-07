#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> priorNums;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            auto it = priorNums.find(nums[i]);
            if (it != priorNums.end() && abs(it->second - i) <= k)
            {
                return true;
            }
            priorNums[nums[i]] = i;
        }
        return false;
    }
};