#include <vector>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        const int OFFSET = 1005;
        if (S >= 2010 - OFFSET || S < -OFFSET)
        {
            return 0;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2010, 0));
        dp[0][OFFSET] = 1;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            for (int j = 0; j < 2010; j++)
            {
                if (j + nums.at(i) < 2010)
                {
                    dp[i + 1][j + nums.at(i)] += dp[i][j];
                }
                if (j - nums.at(i) >= 0)
                {
                    dp[i + 1][j - nums.at(i)] += dp[i][j];
                }
            }
        }
        return dp[nums.size()][OFFSET + S];
    }
};