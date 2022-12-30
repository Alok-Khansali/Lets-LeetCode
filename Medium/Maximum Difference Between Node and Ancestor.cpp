class Solution
{
public:
    int ans = 0;
    void chc(TreeNode *r, int mn, int mx)
    {
        if (r == NULL)
            return;
        mn = min(r->val, mn);
        mx = max(mx, r->val);
        ans = max(ans, abs(mx - mn));
        chc(r->left, mn, mx);
        chc(r->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        chc(root, INT_MAX, INT_MIN);
        return ans;
    }
};