#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }
        auto slow = n;
        auto fast = nextNumber(n);
        while (slow != fast)
        {
            if (slow == 1 || fast == 1)
            {
                return true;
            }
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return slow == 1;
    }

private:
    int nextNumber(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            ret += pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }
};