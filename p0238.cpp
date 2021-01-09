#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }
        vector<int> product(nums.size(), 1);
        int leftProduct = 1, rightProduct = 1;
        for (int i = 1; i < (int)nums.size(); i++)
        {
            leftProduct *= nums.at(i - 1);
            product.at(i) *= leftProduct;
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            rightProduct *= nums.at(i + 1);
            product.at(i) *= rightProduct;
        }
        return product;
    }
};