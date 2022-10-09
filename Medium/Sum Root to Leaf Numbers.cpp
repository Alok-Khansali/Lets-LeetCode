class Solution
{ // Runtime: 3 ms, faster than 72.87% of C++ online submissions for Sum Root to Leaf Numbers.
  // Memory Usage: 9.3 MB, less than 47.41% of C++ online submissions for Sum Root to Leaf Numbers.
public:
    int ans = 0;
    void chc(TreeNode *r, int x)
    {
        if (r == NULL)
            return;
        x *= 10;
        x += r->val;
        if (r->right == NULL && r->left == NULL)
        {
            ans += x;
            return;
        }
        chc(r->left, x);
        chc(r->right, x);
    }
    int sumNumbers(TreeNode *root)
    {
        chc(root, 0);
        return ans;
    }
};