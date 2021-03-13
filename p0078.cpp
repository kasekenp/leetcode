// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 6.9 MB, less than 96.09% of C++ online submissions for Subsets.

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (int bit = 0; bit < (1 << nums.size()); bit++)
        {
            ans.push_back({});
            for (int i = 0; i < (int)nums.size(); i++)
            {
                if (bit & (1 << i))
                {
                    (ans.rbegin())->push_back(nums.at(i));
                }
            }
        }
        return ans;
    }
};