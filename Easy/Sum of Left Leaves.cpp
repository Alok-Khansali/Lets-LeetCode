// Runtime: 8 ms, faster than 48.35% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.2 MB, less than 97.21% of C++ online submissions for Sum of Left Leaves.
class Solution
{
public:
    int sum = 0;
    void chc(TreeNode *r)
    {
        if (r == NULL)
            return;
        if (r->left)
            if (r->left->left == NULL && r->left->right == NULL)
                sum += r->left->val;
        chc(r->left);
        chc(r->right);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        chc(root);
        return sum;
    }
};