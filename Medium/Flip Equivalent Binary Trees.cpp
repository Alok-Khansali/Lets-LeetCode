// Approach 1 : DFS
// 100% faster and 98.18% better on space
class Solution
{
public:
    bool test(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL || r2 == NULL)
            return false;
        if (r1->val != r2->val)
            return false;
        return (test(r1->left, r2->right) && test(r1->right, r2->left)) ||
               (test(r1->left, r2->left) && test(r1->right, r2->right));
    }
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return test(root1, root2);
    }
};