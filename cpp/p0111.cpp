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
public:
    int minDepth(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> Q;
        Q.emplace(root, 1);
        while (!Q.empty())
        {
            TreeNode *node;
            int depth;
            tie(node, depth) = Q.front();
            Q.pop();
            if (node == NULL)
            {
                continue;
            }
            if (node->left == NULL && node->right == NULL)
            {
                return depth;
            }
            Q.emplace(node->left, depth + 1);
            Q.emplace(node->right, depth + 1);
        }
        return 0;
    }
};