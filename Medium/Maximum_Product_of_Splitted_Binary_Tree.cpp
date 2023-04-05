class Solution  // Runtime: 134 ms, faster than 96.10% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// Memory Usage: 90.6 MB, less than 18.18% of C++ online submissions for Maximum Product of Splitted Binary Tree.
{
public:
    long long s = 0, res = 0, m = 1e9 + 7;
    void sum(TreeNode *r)
    {
        if (r == NULL)
            return;
        s += r->val;
        sum(r->left);
        sum(r->right);
    }
    int ans(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        int sl = ans(r->left), sr = ans(r->right);
        res = max({res, (s - sl) * sl, (s - sr) * sr});
        return sl + sr + r->val;
    }
    int maxProduct(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        sum(root);
        ans(root);
        return res % m;
    }
};