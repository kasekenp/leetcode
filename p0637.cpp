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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<pair<long long, int>> values;
        queue<pair<TreeNode *, int>> Q;
        Q.emplace(root, 0);
        while (!Q.empty())
        {
            auto node = Q.front();
            Q.pop();
            if (values.size() <= node.second)
            {
                values.emplace_back(node.first->val, 1);
            }
            else
            {
                values.at(node.second).first += node.first->val;
                values.at(node.second).second++;
            }
            if (node.first->left != NULL)
                Q.emplace(node.first->left, node.second + 1);
            if (node.first->right != NULL)
                Q.emplace(node.first->right, node.second + 1);
        }
        vector<double> res;
        for (auto value : values)
        {
            res.push_back((double)value.first / value.second);
        }
        return res;
    }
};