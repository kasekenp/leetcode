// Runtime: 8 ms, faster than 92.47% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 9.6 MB, less than 90.10% of C++ online submissions for Minimum Path Sum.

#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int i = 0; i < (int)grid.size(); i++)
        {
            for (int j = 0; j < (int)grid[0].size(); j++)
            {
                if (i > 0 && j > 0)
                {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                }
                else if (i > 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else if (j > 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
        return grid[(int)grid.size() - 1][(int)grid[0].size() - 1];
    }
};
