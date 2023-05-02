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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        int l = 1;
        while (!q.empty())
        {
            int x = q.size();
            vector<int> v;
            for (int i = 0; i < x; i++)
            {
                TreeNode *nd = q.front();
                v.push_back(nd->val);
                q.pop();
                if (nd->left)
                    q.push(nd->left);
                if (nd->right)
                    q.push(nd->right);
            }
            if (l != 1)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            l *= -1;
        }
        return ans;
    }
};