class Solution
{ // Memory Usage: 59.7 MB, less than 94.18% of C++ online submissions for Deepest Leaves Sum.
public:
    void get_sum(TreeNode *r, int c, int d, int &s)
    {
        if (r == NULL)
            return;
        get_sum(r->left, c + 1, d, s);
        get_sum(r->right, c + 1, d, s);
        if (c == d)
            s += r->val;
    }
    void call_me(TreeNode *r, int d, int &ans)
    {
        if (r == NULL)
            return;
        call_me(r->left, d + 1, ans);
        call_me(r->right, d + 1, ans);
        ans = max(ans, d);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int dep = 0, sum = 0;
        call_me(root, 0, dep);
        get_sum(root, 0, dep, sum);
        return sum;
    }
};