class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        unordered_map<int, unordered_set<int>> mp;
        queue<TreeNode *> q;
        q.push(root);
        int lev = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                mp[lev].insert(t->val);
                q.pop();
                if (t->left && t->right)
                {
                    if (t->left->val == x && t->right->val == y || t->left->val == y && t->right->val == x)
                        return false;
                }
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (mp[lev].find(x) != mp[lev].end() && mp[lev].find(y) != mp[lev].end())
                return true;
            lev++;
        }
        return false;
    }
};
class Solution  //Better approach
{
    int par[105];
    int depth[105];
    void dfs(TreeNode *cur, int d, int p)
    {
        if (cur == nullptr)
            return;
        par[cur->val] = p;
        depth[cur->val] = d;
        dfs(cur->left, d + 1, cur->val);
        dfs(cur->right, d + 1, cur->val);
    }
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, 0, -1);
        return (par[x] != par[y]) && (depth[x] == depth[y]);
    }
};