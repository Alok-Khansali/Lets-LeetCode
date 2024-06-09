// Runtime: 0ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 14.67 MB, less than 81.87% of C++ online submissions for Sum of Left Leaves.
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

// Approach 2 : no extra function
// 100% fast
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root, bool Left = false)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return (Left) ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};