// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 7.1 MB, less than 57.70% of C++ online submissions for Rotate Image.

#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int y1 = 0, y2 = matrix.size() - 1; y1 < y2; y1++, y2--)
        {
            for (int x1 = y1, x2 = y2; x1 < y2; x1++, x2--)
            {
                swap(matrix[y1][x1], matrix[x1][y2]);
                swap(matrix[y1][x1], matrix[y2][x2]);
                swap(matrix[y1][x1], matrix[x2][y1]);
            }
        }
    }
};