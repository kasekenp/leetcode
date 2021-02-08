#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target)
        {
            return {-1, -1};
        }
        return {(int)distance(nums.begin(), first), (int)distance(nums.begin(), last) - 1};
    }
};
