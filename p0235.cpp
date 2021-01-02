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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p)
            return p;
        if (root == q)
            return q;
        auto leftNode = lowestCommonAncestor(root->left, p, q);
        auto rightNode = lowestCommonAncestor(root->right, p, q);
        if ((leftNode == p && rightNode == q) || (leftNode == q && rightNode == p))
            return root;
        if (leftNode != NULL)
            return leftNode;
        if (rightNode != NULL)
            return rightNode;
        return NULL;
    }
};