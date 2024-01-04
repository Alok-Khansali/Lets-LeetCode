// Runtime: 28 ms, faster than 96.70% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.3 MB, less than 63.86% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
class Solution
{
public:
    TreeNode *ans(TreeNode *r, TreeNode *p, TreeNode *q)
    {
        // If any of the give node is equal to the current node,
        // Return it, because the other node surely lies deeper in the tree
        // If the current node is p, return it
        if (r == p)
            return p;
        // If the current node is q, return it
        if (r == q)
            return q;
        // If both the given nodes lie on the oppposite sides of the current node
        // Then the current node is the Lowest Common Ancestor
        if ((p->val < r->val && q->val > r->val) || (p->val > r->val && q->val < r->val))
            return r;
        // Now its confirme that both the nodes lies in the same subtree of the current node
        // If node p has a value less than the current node
        //  Go to the left subtree
        if (p->val < r->val)
            return ans(r->left, p, q);
        // Else traverse the right subtree
        return ans(r->right, p, q);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        ios_base::sync_with_stdio(0);
        return ans(root, p, q);
    }
};