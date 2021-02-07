#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    map<char, vector<char>> digitToChars;

    void rec(int i, string &digits, vector<string> &res, string cur)
    {
        if (i == digits.size())
        {
            if (i)
            {
                res.push_back(cur);
            }
            return;
        }
        for (auto c : digitToChars.at(digits.at(i)))
        {
            rec(i + 1, digits, res, cur + c);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        for (char c = '2', i = 0; c <= '9'; c++, i += 3)
        {
            digitToChars[c] = {(char)('a' + i), (char)('a' + i + 1), (char)('a' + i + 2)};
            if (c == '7' || c == '9')
            {
                digitToChars[c].push_back((char)'a' + i + 3);
                i++;
            }
        }
        vector<string> res;
        rec(0, digits, res, "");
        return res;
    }
};