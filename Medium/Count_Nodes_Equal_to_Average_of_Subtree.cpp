class Solution
{
public:
    int ans = 0;
    vector<int> trav(TreeNode *r)
    {
        if (r == NULL)
            return {0, 0};
        vector<int> lt = trav(r->left), rt = trav(r->right);
        int sum = r->val + lt[0] + rt[0], count = 1 + lt[1] + rt[1];
        if (sum / count == r->val)
            ans++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode *root)
    {
        trav(root);
        return ans;
    }
};