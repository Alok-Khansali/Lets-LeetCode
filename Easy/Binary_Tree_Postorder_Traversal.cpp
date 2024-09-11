class Solution
{ // Runtime: 4 ms, faster than 40.68% of C++ online submissions for Binary Tree Postorder Traversal.
  // Memory Usage: 8.5 MB, less than 64.64% of C++ online submissions for Binary Tree Postorder Traversal.
public:
    vector<int> ans;
    void post(TreeNode *root)
    {
        if (root == NULL)
            return;
        post(root->left);         // left
        post(root->right);        // root
        ans.push_back(root->val); // root
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        post(root);
        return ans;
    }
};

// All in one place
// 100% faster
class Solution
{
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        postorderTraversal(root->left);  // left
        postorderTraversal(root->right); // right
        ans.push_back(root->val);        // root
        return ans;
    }
};