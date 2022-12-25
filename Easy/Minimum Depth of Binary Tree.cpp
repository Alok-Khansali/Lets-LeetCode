class Solution
{ // Runtime: 455 ms, faster than 69.11% of C++ online submissions for Minimum Depth of Binary Tree.
  // Memory Usage: 144.5 MB, less than 91.17% of C++ online submissions for Minimum Depth of Binary Tree.
public:
    int minDepth(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root == NULL)
            return 0;
        int ans = 1;
        if (root->left && root->right)
            ans += min(minDepth(root->left), minDepth(root->right));
        else if (root->left)
            ans += minDepth(root->left);
        else
            ans += minDepth(root->right);
        return ans;
    }
};