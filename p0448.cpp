#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ret(nums.size());
        for (int i = 1; i <= (int)nums.size(); i++)
        {
            ret[i - 1] = i;
        }

        for (auto num : nums)
        {
            ret[num - 1] = 0;
        }
        ret.erase(std::remove(ret.begin(), ret.end(), 0), ret.end());
        return ret;
    }
};