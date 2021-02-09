#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> prevNums;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (prevNums.find(target - nums[i]) != prevNums.end())
            {
                return {prevNums[target - nums[i]], i};
            }
            prevNums[nums[i]] = i;
        }
        return {-1, -1};
    }
};