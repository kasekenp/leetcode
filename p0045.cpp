// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jump Game II.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Jump Game II.

#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> min_step(nums.size(), 1001);
        min_step[0] = 0;
        for (int i = 0; i < (int)min_step.size(); i++)
        {
            for (int j = i + 1; j < min((int)min_step.size(), i + nums.at(i) + 1); j++)
            {
                min_step[j] = min(min_step[j], min_step[i] + 1);
            }
        }
        return *min_step.rbegin();
    }
};