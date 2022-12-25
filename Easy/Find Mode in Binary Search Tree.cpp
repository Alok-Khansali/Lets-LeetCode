class Solution
{
public:
    vector<int> ans;
    int mx = 1;
    void chc(TreeNode *r, int val, int f)
    {
        if (r == NULL)
            return;
        if (val == r->val)
        {
            f++;
            if (f == mx)
                ans.push_back(val);
            else if (f > mx)
            {
                mx = f;
                ans.clear();
                ans.push_back(val);
            }
            // cout << val << ' ' << f << '\n';
        }
        else
        {
            f = 1;
            if (f == mx)
                ans.push_back(r->val);
        }
        chc(r->left, r->val, f);
        chc(r->right, r->val, f);
    }
    vector<int> findMode(TreeNode *root)
    {
        chc(root, root->val, 0);
        return ans;
    }
};