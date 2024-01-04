class Solution
// Runtime: 11 ms, faster than 29.43% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 13.2 MB, less than 48.96% of C++ online submissions for Binary Tree Paths.
{
public:
    vector<string> ans;
    void chc(TreeNode *r, string s)
    {
        if (s != "")
            s += "->" + to_string(r->val);
        else
            s = to_string(r->val);
        if (r->left == NULL && r->right == NULL)
        {
            ans.push_back(s);
            return;
        }
        if (r->left)
            chc(r->left, s);
        if (r->right)
            chc(r->right, s);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        chc(root, "");
        return ans;
    }
};