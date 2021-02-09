#include <bits/stdc++.h>
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
private:
    int maxDiameter = 0;
    int maxDepth(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        auto leftMaxDepth = maxDepth(node->left);
        auto rightMaxDepth = maxDepth(node->right);
        maxDiameter = max(maxDiameter, leftMaxDepth + rightMaxDepth);
        return max(leftMaxDepth + 1, rightMaxDepth + 1);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return maxDiameter;
    }
};