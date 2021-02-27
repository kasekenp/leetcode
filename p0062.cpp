// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 5.8 MB, less than 92.50% of C++ online submissions for Unique Paths.

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // n+m-2Hm-1 == n+m-2Hn-1
        long long res = 1;
        for (short i = n + m - 2, k = 1; k <= min(m - 1, n - 1); i--, k++)
        {
            res *= i;
            res /= k;
        }
        return res;
    }
};