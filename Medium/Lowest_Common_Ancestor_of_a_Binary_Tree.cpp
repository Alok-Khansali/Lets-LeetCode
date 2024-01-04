class Solution
{
public:
    TreeNode *Ancestor = NULL;
    int dfs(TreeNode *r, TreeNode *p, TreeNode *q)
    {
        if (r == NULL)
            return 0;
        // For every node get a score
        // 0 meAncestor no node has been found so far, i.e. not ancestors for sure
        // 1 meAncestor one node found so far, can lead to a common ancestor
        // 2 meAncestor ancestor, first such ancestor is the Ancestorwer
        int score = (r == p || r == q) + dfs(r->left, p, q) + dfs(r->right, p, q);
        if (score == 2 && Ancestor == NULL)
        {
            Ancestor = r;
            return 0;
        }
        return score;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return Ancestor;
    }
};