class Solution
{ // Runtime: 532 ms, faster than 90.88% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
public:
    void find(TreeNode *o, TreeNode *res, TreeNode *t, TreeNode *&ans)
    {
        ios_base::sync_with_stdio(false);
        if (o == NULL) // Using inorder
            return;
        find(o->left, res->left, t, ans); // Go Left
        if (o == t)                       // Check Node
        {
            ans = res; // Here we check if the node is same as target
            return;    // If Yes Store and return
        }
        find(o->right, res->right, t, ans); // Go Right
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        ios_base::sync_with_stdio(false);
        TreeNode *ans;
        find(original, cloned, target, ans);
        return ans;
    }
};