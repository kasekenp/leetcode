#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN, prevSum = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (prevSum + nums[i] >= 0)
            {
                prevSum = max(prevSum + nums[i], nums[i]);
            }
            else
            {
                prevSum = nums[i];
            }
            maxSum = max(maxSum, prevSum);
        }
        return maxSum;
    }
};