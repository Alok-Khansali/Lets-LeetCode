class Solution
{ // Runtime: 4 ms, faster than 40.68% of C++ online submissions for Binary Tree Postorder Traversal.
  // Memory Usage: 8.5 MB, less than 64.64% of C++ online submissions for Binary Tree Postorder Traversal.
public:
    vector<int> ans;
    void post(TreeNode *r)
    {
        if (r == NULL)
            return;
        post(r->left);         // left
        post(r->right);        // root
        ans.push_back(r->val); // root
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        post(root);
        return ans;
    }
};