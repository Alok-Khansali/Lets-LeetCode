class Solution // Work out the math again
{
public:
    int minimumMoves = 0;
    int moves(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        int left = moves(r->left), right = moves(r->right);
        minimumMoves += abs(left) + abs(right);
        // cout << minimumMoves << ' ';
        return r->val + left + right - 1;
    }
    int distributeCoins(TreeNode *root)
    {
        moves(root);
        return minimumMoves;
    }
};