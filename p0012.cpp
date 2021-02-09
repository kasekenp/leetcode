#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        char romanSymbols1[4] = {'I', 'X', 'C', 'M'};
        char romanSymbols2[4] = {'V', 'L', 'D', ' '};
        int digit = 0;
        while (num)
        {
            if (num % 10 == 4)
            {
                roman += romanSymbols2[digit];
                roman += romanSymbols1[digit];
            }
            else if (num % 10 == 9)
            {
                roman += romanSymbols1[digit + 1];
                roman += romanSymbols1[digit];
            }
            else
            {
                for (int i = 0; i < num % 5; i++)
                {
                    roman += romanSymbols1[digit];
                }
                if (num % 10 >= 5)
                {
                    roman += romanSymbols2[digit];
                }
            }
            digit++;
            num /= 10;
        }
        reverse(roman.begin(), roman.end());
        return roman;
    }
};