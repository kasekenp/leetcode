#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ret = (int)nums.size();
        for (int i = 0; i < (int)nums.size(); i++)
        {
            ret = ret ^ (nums[i] ^ i);
        }
        return ret;
    }
};