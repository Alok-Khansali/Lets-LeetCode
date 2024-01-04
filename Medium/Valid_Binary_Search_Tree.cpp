class Solution
{ // Runtime: 15 ms, faster than 77.77% of C++ online submissions for Validate Binary Search Tree.
  // Memory Usage: 21.7 MB, less than 30.71% of C++ online submissions for Validate Binary Search Tree.
public:
    bool bst(TreeNode *r, long mn, long mx)
    {
        if (r == NULL)
            return true;
        if (r->val <= mn || r->val >= mx)
            return false;
        return bst(r->left, mn, r->val) && bst(r->right, r->val, mx);
    }
    bool isValidBST(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        return bst(root, -10000000000, 10000000000);
    }
};