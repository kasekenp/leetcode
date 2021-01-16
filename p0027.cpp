#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int last = nums.size() - 1, res = 0;
        for (int i = 0; i <= last; i++)
        {
            while (nums.at(i) == val && i < last)
            {
                swap(nums.at(i), nums.at(last));
                last--;
            }
            if (nums.at(i) != val)
            {
                res = i + 1;
            }
        }
        return res;
    }
};