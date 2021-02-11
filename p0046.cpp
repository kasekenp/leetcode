#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector<bool> &used, vector<int> &cur, vector<int> &nums, vector<vector<int>> &permutations)
    {
        if (cur.size() == nums.size())
        {
            permutations.push_back({});
            for (auto num : cur)
            {
                (*(permutations.end() - 1)).push_back(num);
            }
            return;
        }
        for (int i = 0; i < (int)used.size(); i++)
        {
            if (used.at(i))
            {
                continue;
            }
            used.at(i) = true;
            cur.push_back(nums.at(i));
            dfs(used, cur, nums, permutations);
            used.at(i) = false;
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> permutations;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        dfs(used, cur, nums, permutations);
        return permutations;
    }
};