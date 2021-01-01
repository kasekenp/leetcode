#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0, r = arr.size() - 1;
        while (r - l > 1)
        {
            int m = (r + l) / 2;
            if (arr[m - 1] < arr[m] && arr[m] > arr[m + 1])
                return m;
            else if (arr[m - 1] < arr[m])
                l = m;
            else
                r = m;
        }
        return -1;
    }
};