class Solution // First Draft, when i didnt use new TreeNode() Correctly
// Runtime: 40 ms, faster than 31.26% of C++ online submissions for Add One Row to Tree.
// Memory Usage: 24.8 MB, less than 98.26% of C++ online submissions for Add One Row to Tree.
{
public:
    void do_it(TreeNode *r, int v, int d, int l)
    {
        if (r == NULL)
            return;
        if (d == l + 1)
        {
            TreeNode *x = r->left, *y = r->right, *a = new TreeNode(v), *b = new TreeNode(v);
            r->left = a;
            a->left = x;
            r->right = b;
            b->right = y;
            return;
        }
        do_it(r->left, v, d, l + 1);
        do_it(r->right, v, d, l + 1);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *x = new TreeNode(val);
            x->left = root;
            return x;
        }
        do_it(root, val, depth, 1);
        return root;
    }
};

// Draft 2, same approach just a better way to write it
class Solution
{ // Runtime: 39 ms, faster than 34.83% of C++ online submissions for Add One Row to Tree.
  // Memory Usage: 24.8 MB, less than 98.26% of C++ online submissions for Add One Row to Tree.
public:
    void do_it(TreeNode *r, int v, int d, int l)
    {
        if (r == NULL)
            return;
        if (d == l + 1)
        {
            r->left = new TreeNode(v, r->left, NULL), r->right = new TreeNode(v, NULL, r->right);
            return;
        }
        do_it(r->left, v, d, l + 1);
        do_it(r->right, v, d, l + 1);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        ios_base::sync_with_stdio(0);
        if (depth == 1)
            return new TreeNode(val, root, NULL);
        do_it(root, val, depth, 1);
        return root;
    }
};