// Runtime: 20 ms, faster than 80.38% of C++ online submissions for Merge Intervals.
// Memory Usage: 14 MB, less than 96.77% of C++ online submissions for Merge Intervals.

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int last = 0;
        for (int i = 1; i < (int)intervals.size(); i++)
        {
            if (intervals[last][1] < intervals[i][0])
            {
                last++;
                intervals[last] = intervals[i];
            }
            else
            {
                intervals[last][1] = max(intervals[last][1], intervals[i][1]);
            }
        }
        intervals.erase(intervals.begin() + last + 1, intervals.end());
        return intervals;
    }
};
