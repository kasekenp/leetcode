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
        unordered_map<string, vector<string>> hash;
        for (auto str : strs)
        {
            auto sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            hash[sortedStr].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto p : hash)
        {
            ret.push_back(p.second);
        }
        return ret;
    }
};