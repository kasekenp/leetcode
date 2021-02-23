// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.8 MB, less than 86.08% of C++ online submissions for Pow(x, n).

#include <stdlib.h>

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        for (int i = 0, m = abs(n); m > 0; i++, m /= 2)
        {
            if (m % 2)
            {
                ans *= x;
            }
            x = x * x;
        }
        return n >= 0 ? ans : (double)(1.0 / ans);
    }
};
