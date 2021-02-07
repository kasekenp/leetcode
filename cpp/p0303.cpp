#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    vector<int> s;

public:
    NumArray(vector<int> &nums)
    {
        s.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return s[j + 1] - s[i];
    }
};