#include <string>
using namespace std;

class Solution
{
public:
    void checkString(string &s, int l, int r, int &len, int &left)
    {
        if (s[l] == s[r])
        {
            while (0 <= l - 1 && r + 1 < s.size() && s[l - 1] == s[r + 1])
            {
                l--, r++;
            }
            if (r - l + 1 > len)
            {
                left = l;
                len = r - l + 1;
            }
        }
    }

    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int left = 0, len = 1;
        for (int i = 1; i < (int)s.size() - 1; i++)
        {
            checkString(s, i - 1, i + 1, len, left);
        }
        for (int i = 1; i < (int)s.size(); i++)
        {
            checkString(s, i - 1, i, len, left);
        }
        return s.substr(left, len);
    }
};