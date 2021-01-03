#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> previousNums(nums.size() + 1);
        for (auto num : nums)
        {
            if (previousNums[num])
            {
                return num;
            }
            previousNums[num] = true;
        }
        return -1;
    }
};