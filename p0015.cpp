#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto first = nums.begin();
        while (first + 2 < nums.end())
        {
            if (first != nums.begin() && *first == *(first - 1))
            {
                first++;
                continue;
            }
            auto second = first + 1, third = nums.end() - 1;
            while (second < third)
            {
                int sum = *first + *second + *third;
                if (sum == 0)
                {
                    res.push_back({*first, *second, *third});
                    second++, third--;
                    while (second < third && *second == *(second - 1) && *third == *(third + 1))
                    {
                        second++, third--;
                    }
                }
                else if (sum < 0)
                {
                    second++;
                }
                else
                {
                    third--;
                }
            }
            first++;
        }
        return res;
    }
};