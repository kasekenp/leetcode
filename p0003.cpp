#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0, r = 0;
        unordered_map<char, int> prevChars;
        for (int l = 0; l < (int)s.size(); l++)
        {
            while (r < (int)s.size())
            {
                if (prevChars.find(s[r]) != prevChars.end() && prevChars[s[r]] >= l)
                {
                    l = prevChars[s[r]];
                    prevChars[s[r]] = r;
                    r++;
                    break;
                }
                maxLength = max(maxLength, r - l + 1);
                prevChars[s[r]] = r;
                r++;
            }
        }
        return maxLength;
    }
};