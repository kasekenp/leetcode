#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        auto chmax = [&](int i, int j, int k) {
            if (abs(nums[i] + nums[j] + nums[k] - target) < diff)
            {
                diff = abs(nums[i] + nums[j] + nums[k] - target);
                ans = nums[i] + nums[j] + nums[k];
            }
        };
        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            for (int j = i + 1; j < (int)nums.size() - 1; j++)
            {
                int k = distance(nums.begin(), lower_bound(nums.begin() + (j + 1), nums.end(), target - nums[i] - nums[j]));
                if (k == nums.size())
                {
                    chmax(i, j, k - 1);
                }
                else if (k == j + 1)
                {
                    chmax(i, j, k);
                }
                else
                {
                    chmax(i, j, k);
                    chmax(i, j, k - 1);
                }
            }
        }
        return ans;
    }
};
