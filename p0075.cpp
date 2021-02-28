// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.2 MB, less than 79.08% of C++ online submissions for Sort Colors.

#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p = nums.size() - 1;
        while (p >= 0 && nums[p] == 2)
        {
            p--;
        }
        for (int i = 0; i < p; i++)
        {
            if (nums[i] == 2)
            {
                swap(nums[i], nums[p]);
                while (nums[p] == 2 && p - 1 >= 0)
                {
                    p--;
                }
            }
        }
        p = 0;
        while (p < nums.size() && nums[p] == 0)
        {
            p++;
        }
        for (int i = p; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p]);
                while (nums[p] == 0 && p + 1 < nums.size())
                {
                    p++;
                }
            }
        }
    }
};
