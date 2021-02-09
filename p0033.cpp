#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }
        if (target < nums.at(0))
        {
            int l = -1, r = nums.size();
            while (r - l > 1)
            {
                int m = (r + l) / 2;
                if (nums.at(m) == target)
                {
                    return m;
                }
                else if (nums.at(m) >= nums.at(0) || nums.at(m) < target)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
        }
        else
        {
            int l = -1, r = nums.size();
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (nums.at(m) == target)
                {
                    return m;
                }
                else if (nums.at(m) < nums.at(0) || nums.at(m) > target)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
        }
        return -1;
    }
};
