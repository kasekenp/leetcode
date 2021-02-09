#include <functional>
#include <vector>
using namespace std;

class Solution
{
private:
    void rec(int i, int j, vector<vector<vector<pair<int, int>>>> &from, vector<int> candidates, vector<vector<int>> &ans, vector<int> cur)
    {
        if (j == 0)
        {
            if (cur.size())
            {
                ans.push_back(cur);
            }
            return;
        }
        for (auto p : from[i][j])
        {
            if (p.first == i)
            {
                cur.push_back(candidates.at(i));
            }
            rec(p.first, p.second, from, candidates, ans, cur);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<vector<pair<int, int>>>> from(candidates.size() + 1, vector<vector<pair<int, int>>>(target + 1));
        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (j > 0 && from[i][j].empty())
                {
                    continue;
                }
                from[i + 1][j].emplace_back(i, j);
                if (j + candidates.at(i) <= target)
                {
                    from[i][j + candidates.at(i)].emplace_back(i, j);
                }
            }
        }
        vector<vector<int>> ans;
        rec(candidates.size(), target, from, candidates, ans, {});
        return ans;
    }
};