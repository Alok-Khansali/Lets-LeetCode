class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int mx = INT_MIN, ans = 1, lev = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size(), sum = 0;
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                sum += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (sum > mx)
                ans = lev, mx = sum;
            lev++;
        }
        return ans;
    }
};