#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root, long long maxValue = INT_MAX, long long minValue = INT_MIN)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val < minValue || maxValue < root->val)
        {
            return false;
        }
        return isValidBST(root->left, (long long)root->val - 1, minValue) && isValidBST(root->right, maxValue, (long long)root->val + 1);
    }
};