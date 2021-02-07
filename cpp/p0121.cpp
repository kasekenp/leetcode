#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = 1 << 30, maxProfit = 0;
        for (auto price : prices)
        {
            minPrice = min(price, minPrice);
            maxProfit = max(price - minPrice, maxProfit);
        }
        return maxProfit;
    }
};