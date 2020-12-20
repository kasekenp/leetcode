#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> chars;
        for (int i = 0; i < (int)t.size(); i++)
        {
            chars[t[i]]++;
        }
        for (int i = 0; i < (int)s.size(); i++)
        {
            chars[s[i]]--;
        }
        char ans;
        for (auto c : chars)
        {
            if (c.second)
            {
                ans = c.first;
            }
        }
        return ans;
    }
};