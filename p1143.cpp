// Runtime: 20 ms, faster than 56.86% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 13 MB, less than 26.74% of C++ online submissions for Longest Common Subsequence.

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> lcs(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= (int)text1.size(); i++)
        {
            for (int j = 1; j <= (int)text2.size(); j++)
            {
                if (text1.at(i - 1) == text2.at(j - 1))
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else
                {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        return lcs[text1.size()][text2.size()];
    }
};