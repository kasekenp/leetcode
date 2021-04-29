// Runtime: 4 ms, faster than 75.90% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.3 MB, less than 76.60% of C++ online submissions for Symmetric Tree.

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
    bool dfs(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr && rightNode == nullptr)
        {
            return true;
        }
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val)
        {
            return false;
        }
        return dfs(leftNode->left, rightNode->right) && dfs(leftNode->right, rightNode->left);
    }

public:
    bool isSymmetric(TreeNode *n1)
    {
        return dfs(root->left, root->right);
    }
};