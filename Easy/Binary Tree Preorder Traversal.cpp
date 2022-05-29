class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
  // Memory Usage: 8.3 MB, less than 78.19% of C++ online submissions for Binary Tree Preorder Traversal.
public:
    vector<int> ans;
    void pre(TreeNode *r)
    {
        if (r == NULL)
            return;
        ans.push_back(r->val); // root
        pre(r->left);          // left
        pre(r->right);         // right
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        pre(root);
        return ans;
    }
};
/*
