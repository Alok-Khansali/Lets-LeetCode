class Solution
{
public:
    int val, ht = -1;
    void help(TreeNode *r, int l, int h)
    {
        if (r == NULL)
            return;
        help(r->left, l + 1, h + 1);
        help(r->right, l - 1, h + 1);
        if (ht < h)
            val = r->val, ht = h;
    }
    int findBottomLeftValue(TreeNode *root)
    {
        help(root, 0, 0);
        return val;
    }
};