#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        map<char, int> romanCharToInt = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (i + 1 != s.size() && romanCharToInt[s[i + 1]] > romanCharToInt[s[i]])
            {
                ans -= romanCharToInt[s[i]];
            }
            else
            {
                ans += romanCharToInt[s[i]];
            }
        }
        return ans;
    }
};