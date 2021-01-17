#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> prevParentheses;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                prevParentheses.push(c);
            }
            else if (c == ')' || c == '}' || c == ']')
            {
                if (prevParentheses.empty() || prevParentheses.top() != pairs[c])
                {
                    return false;
                }
                prevParentheses.pop();
            }
        }
        return prevParentheses.empty();
    }
};