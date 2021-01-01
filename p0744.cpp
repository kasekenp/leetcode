#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? *letters.begin() : *it;
    }
};