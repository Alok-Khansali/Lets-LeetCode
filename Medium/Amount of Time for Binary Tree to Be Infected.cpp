class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> mp;
    TreeNode *st;
    int chc;
    void parent(TreeNode *r)
    {
        if (r->val == chc)
            st = r;
        if (r->left)
        {
            mp[r->left] = r;
            parent(r->left);
        }
        if (r->right)
        {
            mp[r->right] = r;
            parent(r->right);
        }
    }
    int amountOfTime(TreeNode *root, int start)
    {
        ios_base::sync_with_stdio(0);
        int ans = -1;
        chc = start;
        parent(root);
        queue<TreeNode *> q;
        q.push(st);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *tp = q.front();
                q.pop();
                tp->val = -1;
                if (tp->left && tp->left->val > 0)
                    q.push(tp->left);
                if (tp->right && tp->right->val > 0)
                    q.push(tp->right);
                if (mp[tp] && mp[tp]->val > 0)
                    q.push(mp[tp]);
            }
            ans++;
        }
        return ans;
    }
};