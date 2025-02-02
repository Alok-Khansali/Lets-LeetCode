/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Straight forward bfs
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int mx = INT_MIN, len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *tp = q.front();
                q.pop();
                mx = max(mx, tp->val);
                if (tp->left)
                    q.push(tp->left);
                if (tp->right)
                    q.push(tp->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};