class Solution
{ // Runtime: 5 ms, faster than 31.20% of C++ online submissions for Same Tree.
  // Memory Usage: 10 MB, less than 44.45% of C++ online submissions for Same Tree.
public:
    bool chc(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL && q != NULL || q == NULL && p != NULL)
            return false;
        if (p->val != q->val)
            return false;
        return (chc(p->left, q->left) && chc(p->right, q->right));
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        ios_base::sync_with_stdio(0);
        return chc(p, q);
    }
};