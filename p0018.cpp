#include <algorithm>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> fourNumbers;
        set<tuple<int, int, int, int>> previousFourNumbers;
        unordered_map<int, vector<pair<pair<int, int>, pair<int, int>>>> previousPairs;
        for (int i = 0; i < (int)nums.size() - 1; i++)
        {
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                if (previousPairs.find(target - nums[i] - nums[j]) != previousPairs.end())
                {
                    for (auto pair2 : previousPairs[target - nums[i] - nums[j]])
                    {
                        auto numsk = pair2.first.first, k = pair2.first.second, numsl = pair2.second.first, l = pair2.second.second;
                        if (i == k || i == l || j == k || j == l)
                        {
                            continue;
                        }
                        vector<int> v = {nums[i], nums[j], numsk, numsl};
                        sort(v.begin(), v.end());
                        auto t = make_tuple(v[0], v[1], v[2], v[3]);
                        if (previousFourNumbers.find(t) == previousFourNumbers.end())
                        {
                            fourNumbers.push_back(v);
                            previousFourNumbers.insert(t);
                        }
                    }
                }
                if (previousPairs.find(nums[i] + nums[j]) == previousPairs.end())
                {
                    previousPairs[nums[i] + nums[j]] = {{{nums[i], i}, {nums[j], j}}};
                }
                else
                {
                    previousPairs[nums[i] + nums[j]].push_back({{nums[i], i}, {nums[j], j}});
                }
            }
        }
        return fourNumbers;
    }
};