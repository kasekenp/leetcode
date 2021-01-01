#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int totalProduct = 1, zeros = 0;
        for (auto num : nums)
        {
            if (num)
            {
                totalProduct *= num;
            }
            else
            {
                zeros++;
            }
        }
        if (zeros >= 2)
        {
            for (auto &num : nums)
            {
                num = 0;
            }
        }
        else if (zeros == 1)
        {
            for (auto &num : nums)
            {
                if (num)
                    num = 0;
                else
                    num = totalProduct;
            }
        }
        else
        {
            for (auto &num : nums)
            {
                num = totalProduct / num;
            }
        }
        return nums;
    }
};