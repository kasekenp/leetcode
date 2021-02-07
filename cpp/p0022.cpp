#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    void generateString(string s, int i, int prevCount, vector<string> &res, int &n)
    {
        if (i == 2 * n)
        {
            res.push_back(s);
        }
        else if (prevCount == 0)
        {
            generateString(s + '(', i + 1, prevCount + 1, res, n);
        }
        else if (prevCount == 2 * n - i)
        {
            generateString(s + ')', i + 1, prevCount - 1, res, n);
        }
        else
        {
            generateString(s + '(', i + 1, prevCount + 1, res, n);
            generateString(s + ')', i + 1, prevCount - 1, res, n);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generateString("", 0, 0, res, n);
        return res;
    }
};