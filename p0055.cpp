// Runtime: 8 ms, faster than 93.24% of C++ online submissions for Jump Game.
// Memory Usage: 12.7 MB, less than 85.74% of C++ online submissions for Jump Game.

#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        for (unsigned short i = 1; i < (unsigned short)nums.size(); i++)
        {
            if (i > nums.at(0))
            {
                return false;
            }
            nums.at(0) = max(nums.at(0), i + nums.at(i));
        }
        return true;
    }
};