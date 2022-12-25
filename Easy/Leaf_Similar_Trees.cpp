class Solution
{
public:
    void chc(TreeNode *r, vector<int> &v)
    {
        if (r == NULL)
            return;
        if (r->left == NULL && r->right == NULL)
        {
            v.push_back(r->val);
            return;
        }
        chc(r->left, v);
        chc(r->right, v);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        chc(root1, v1);
        chc(root2, v2);
        return (v1 == v2);
    }
};