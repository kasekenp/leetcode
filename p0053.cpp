#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> maxl(n, -(1LL << 62)), maxr(n, -(1LL << 62));
        maxr[0] = nums[0];
        maxl[n - 1] = nums[n - 1];
        long long ans = max(nums[0], nums[n - 1]);
        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            maxr[i] = max<long long>(maxr[i - 1] + nums[i], nums[i]);
            maxl[j] = max<long long>(maxl[j + 1] + nums[j], nums[j]);
            ans = max({ans, maxl[i], maxr[i]});
        }
        return ans;
    }
};