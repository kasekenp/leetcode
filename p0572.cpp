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
    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
        {
            return true;
        }
        if (s == NULL || t == NULL)
        {
            return false;
        }
        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
        {
            return true;
        }
        if (s == NULL || t == NULL)
        {
            return false;
        }
        if (s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right))
        {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};