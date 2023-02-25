class Solution //100% faster, 95.24% better space
{
public:
    bool chc(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL) // If the node reach an endpoint together, say true
            return true;
        if (p == NULL && q != NULL || q == NULL && p != NULL) // If only either of the nodes reach an end point, say false
            return false;
        if (p->val != q->val) // If none of the nodes are at the end points but there values differ, say false
            return false;
        return (chc(p->left, q->left) && chc(p->right, q->right));   
        // && is used instead of & as it short circuits the condition
        // i.e. it stops checking the conditions when a false is received (in the case of &&)
        // and in the case of ||, it stops checking when a true value is received
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return chc(p, q);
    }
};