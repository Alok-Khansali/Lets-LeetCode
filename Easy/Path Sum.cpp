// Runtime: 9 ms, faster than 91.49% of C++ online submissions for Path Sum.
// Memory Usage: 21.4 MB, less than 38.76% of C++ online submissions for Path Sum.
class Solution
{
public:
    bool ans = false;
    bool chc(TreeNode *r, int ts)
    {
        if (ans)
            return ans;
        if (r == NULL)
            return false;
        ts -= r->val;
        if (r->left == NULL && r->right == NULL && ts == 0)
            return true;
        ans += chc(r->left, ts) + chc(r->right, ts);
        return ans;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        ios_base::sync_with_stdio(0);
        return chc(root, targetSum);
    }
};

// Slightly cool and short
// Runtime: 11 ms, faster than 89.08% of C++ online submissions for Path Sum.
// Memory Usage: 21.4 MB, less than 38.76% of C++ online submissions for Path Sum.
class Solution
{
public:
    bool chc(TreeNode *r, int ts)
    {
        if (r == NULL)
            return false;
        ts -= r->val;
        if (r->left == NULL && r->right == NULL && ts == 0)
            return true;
        return chc(r->left, ts) || chc(r->right, ts);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return chc(root, targetSum);
    }
};