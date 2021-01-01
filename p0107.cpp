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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> Q;
        Q.emplace(root, 0);
        while (Q.size())
        {
            auto node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if (res.size() <= depth)
            {
                res.push_back({node->val});
            }
            else
            {
                res.at(depth).push_back(node->val);
            }
            if (node->left != NULL)
            {
                Q.emplace(node->left, depth + 1);
            }
            if (node->right != NULL)
            {
                Q.emplace(node->right, depth + 1);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};