class Solution
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.4 MB, less than 74.94% of C++ online submissions for Binary Tree Inorder Traversal.
{
public:
    vector<int> ans;
    void inorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        inorder(r->left);      // Left
        ans.push_back(r->val); // Root
        inorder(r->right);     // Right
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        inorder(root);
        return ans;
    }
};