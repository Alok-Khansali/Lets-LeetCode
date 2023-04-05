class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int x = q.size();
            vector<int> v;
            for (int i = 0; i < x; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};