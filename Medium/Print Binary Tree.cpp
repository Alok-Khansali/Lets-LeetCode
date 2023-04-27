class Solution
{
public:
    void dfs(TreeNode *n, vector<vector<string>> &v, int r, int c, int h)
    {
        if(n->left)
        {
            v[r+1][c - (1 << (h - r - 2))] = to_string(n->left->val);
            dfs(n->left, v, r+1, c - (1 << (h - r - 2)), h);
        } 
        if(n->right)
        {
            v[r+1][c + (1 << (h - r - 2))] = to_string(n->right->val);
            dfs(n->right, v, r+1, c + (1 << (h - r - 2)), h);
        }
    }
    int ht(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        int lt = 1 + ht(r->left), rt = 1 + ht(r->right);
        return max(lt, rt);
    }
    vector<vector<string>> printTree(TreeNode *root)
    {
        int h = ht(root), l = ((1<<h) - 1);
        vector<vector<string>> ans(h, vector<string>(l));
        ans[0][l/2] = to_string(root->val);
        dfs(root, ans, 0, l/2, h);
        return ans;
    }
};