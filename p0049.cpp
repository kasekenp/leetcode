// Runtime: 36 ms, faster than 80.49% of C++ online submissions for Group Anagrams.
// Memory Usage: 18.2 MB, less than 96.05% of C++ online submissions for Group Anagrams.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        unordered_map<string, int> hash;
        for (auto str : strs)
        {
            auto sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            if (hash.find(sortedStr) == hash.end())
            {
                hash[sortedStr] = (int)ret.size();
                ret.push_back({str});
            }
            else
            {
                ret.at(hash[sortedStr]).push_back(str);
            }
        }
        return ret;
    }
};