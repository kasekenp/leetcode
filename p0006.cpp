#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        bool down = true;
        int r = 0;
        vector<string> str(numRows, "");
        for (int i = 0; i < (int)s.size(); i++)
        {
            str.at(r) += s[i];
            r += down ? 1 : -1;
            if (r == 0 || r == numRows - 1)
            {
                down = !down;
            }
        }
        string ret = "";
        for (int i = 0; i < numRows; i++)
        {
            ret += str[i];
        }
        return ret;
    }
};