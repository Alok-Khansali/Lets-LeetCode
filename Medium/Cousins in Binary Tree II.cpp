class Solution // Not so fast
{
public:
    unordered_map<int, int> mp;
    unordered_map<TreeNode *, int> sib_sum;
    void dfs(TreeNode *par, int lev)
    {
        if (par->left)
        {
            par->left->val = mp[lev + 1] - sib_sum[par];
            dfs(par->left, lev + 1);
        }
        if (par->right)
        {
            par->right->val = mp[lev + 1] - sib_sum[par];
            dfs(par->right, lev + 1);
        }
    }
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int lev = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                mp[lev] += t->val;
                q.pop();
                if (t->left)
                    q.push(t->left), sib_sum[t] += t->left->val;
                if (t->right)
                    q.push(t->right), sib_sum[t] += t->right->val;
            }
            lev++;
        }
        root->val = 0;
        dfs(root, 0);
        return root;
    }
};
// NO DFS
class Solution // 75% faster
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        unordered_map<int, int> mp;
        queue<TreeNode *> q;
        q.push(root);
        int lev = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                t->val += mp[lev];
                q.pop();
                int x = ((t->left) ? t->left->val : 0) + ((t->right) ? t->right->val : 0);
                if (t->left)
                    q.push(t->left), mp[lev + 1] += t->left->val, t->left->val = -x;
                if (t->right)
                    q.push(t->right), mp[lev + 1] += t->right->val, t->right->val = -x;
            }
            lev++;
        }
        root->val = 0;
        return root;
    }
};