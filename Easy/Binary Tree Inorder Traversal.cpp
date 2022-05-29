class Solution
{
public:
    vector<int> ans;
    void iord(TreeNode *r)
    {
        if (r == NULL)
            return;
        iord(r->left);         // Left
        ans.push_back(r->val); // Root
        iord(r->right);        // Right
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        iord(root);
        return ans;
    }
};