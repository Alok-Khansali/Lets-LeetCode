// storing values
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root->left == NULL)
            return root->val;
        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);
        if (root->val == 2)
            return left | right;
        return left & right;
    }
};
// Using short circuiting in logical operators
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root->left == NULL)
            return root->val;
        if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};