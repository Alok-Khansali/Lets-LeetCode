class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 1;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int mx = q.size(), st = q.front().second, lst = q.back().second;
            ans = max(ans, lst - st + 1);
            for (int i = 0; i < mx; ++i)
            {
                auto pos_ptr = q.front();
                TreeNode *nd = pos_ptr.first;
                int nd_index = pos_ptr.second - st;
                q.pop();
                if (nd->left != nullptr)
                    q.push({nd->left, 2LL * nd_index + 1});
                if (nd->right != nullptr)
                    q.push({nd->right, 2LL * nd_index + 2});
            }
        }
        return ans;
    }
};